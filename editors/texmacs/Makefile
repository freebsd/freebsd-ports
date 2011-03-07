# New ports collection makefile for:	texmacs
# Date created:		1 December 2001
# Whom:			Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	texmacs
PORTVERSION=	1.0.7.9
CATEGORIES=	editors print
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/%SUBDIR%/ \
		http://www.predatorlabs.net/dl/
MASTER_SITE_SUBDIR=	targz old-targz
DISTNAME=	TeXmacs-${PORTVERSION}-src

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	A free WYSIWYG scientific text editor

BUILD_DEPENDS=	tex:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX-base

MAKE_JOBS_SAFE=	yes

USE_PYTHON=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GHOSTSCRIPT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-optimize="${CXXFLAGS}" \
		--with-iconv="${LOCALBASE}"

MAKE_ARGS=	CP="${CP} -R -f"
ALL_TARGET=	${PORTNAME:U}

DATADIR=	${PREFIX}/share/TeXmacs

MAN1=		texmacs.1 fig2ps.1
MANCOMPRESSED=	yes

OPTIONS=	IMLIB2 "Use imlib2" ON \
		PDF "Experimental PDF renderer" OFF \
		QT4 "Experimental QT4 GUI" OFF

DESKTOP_ENTRIES=	"TeXmacs" "${COMMENT}" \
			"${DATADIR}/misc/pixmaps/TeXmacs.xpm" "texmacs" \
			"Application;Education;Science;" false

.include <bsd.port.options.mk>

.if !defined(WITHOUT_IMLIB2)
USE_EFL=	imlib2
CONFIGURE_ARGS+=	--with-imlib2
.endif

.if !defined(WITHOUT_PDF)
CONFIGURE_ARGS+=	--enable-pdf-renderer
.endif

.if !defined(WITHOUT_QT4)
CONFIGURE_ARGS+=	--enable-qt
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build uic_build
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		 's|#!/bin/bash|#!/bin/sh|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete
	@${REINPLACE_CMD} -e 's|ICONV_LDFLAGS/-liconv|ICONV_LDFLAGS|' \
		${WRKSRC}/configure

post-install:
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${PREFIX}/libexec/TeXmacs
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.include <bsd.port.post.mk>
