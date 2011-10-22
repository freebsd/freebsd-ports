# New ports collection makefile for:	texmacs
# Date created:		1 December 2001
# Whom:			Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	texmacs
PORTVERSION=	1.0.7.13
CATEGORIES=	editors print
MASTER_SITES=	http://www.texmacs.org/Download/ftp/tmftp/source/ \
		http://www.predatorlabs.net/dl/
DISTNAME=	TeXmacs-${PORTVERSION}-src

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	A free WYSIWYG scientific text editor

BUILD_DEPENDS=	tex:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	guile.21:${PORTSDIR}/lang/guile
RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX-base

MAKE_JOBS_SAFE=	yes

USE_PYTHON=	yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-optimize="${CXXFLAGS}"
MAKE_ARGS=	CP="${CP} -R -f"
ALL_TARGET=	${PORTNAME:U}

DATADIR=	${PREFIX}/share/TeXmacs

MAN1=		texmacs.1 fig2ps.1
MANCOMPRESSED=	yes

OPTIONS=	FREETYPE "FreeType support" ON \
		GHOSTSCRIPT "Ghostscript support" ON \
		ICONV "Iconv support" ON \
		IMLIB2 "Use imlib2" ON \
		PDF "Experimental PDF renderer" OFF \
		QT4 "QT4 GUI" ON

DESKTOP_ENTRIES=	"TeXmacs" "${COMMENT}" \
			"${DATADIR}/misc/pixmaps/TeXmacs.xpm" "texmacs" \
			"Application;Education;Science;" false

.include <bsd.port.options.mk>

.if !defined(WITHOUT_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--with-freetype=linked
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

.if !defined(WITHOUT_GHOSTSCRIPT)
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--with-gs=yes
.else
CONFIGURE_ARGS+=	--without-gs
.endif

.if !defined(WITHOUT_ICONV)
USE_ICONV=	yes
CONFIGURE_ARGS+=	--with-iconv="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

.if !defined(WITHOUT_IMLIB2)
USE_EFL=	imlib2
CONFIGURE_ARGS+=	--with-imlib2
.else
CONFIGURE_ARGS+=	--without-imlib
.endif

.if !defined(WITHOUT_PDF)
CONFIGURE_ARGS+=	--enable-pdf-renderer
.endif

.if !defined(WITHOUT_QT4)
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build rcc uic_build
CONFIGURE_ARGS+=	--with-qt --enable-qtpipes
.else
CONFIGURE_ARGS+=	--disable-qt
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		 's|#!/bin/bash|#!/bin/sh|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete
	@${REINPLACE_CMD} -e 's|ICONV_LDFLAGS/-liconv|ICONV_LDFLAGS|' \
		${WRKSRC}/configure
	#fix for namespace clash with Qt3
	@${REINPLACE_CMD} -e 's|qdrawutil.h|qt4/Qt/qdrawutil.h|' \
		${WRKSRC}/src/Plugins/Qt/QTMStyle.cpp

post-install:
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${PREFIX}/libexec/TeXmacs
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.include <bsd.port.post.mk>
