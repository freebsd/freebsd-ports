# Created by: Geoffrey Mainland <mainland@apeiron.net>
# $FreeBSD$

PORTNAME=	texmacs
PORTVERSION=	1.0.7.14
PORTREVISION=	1
CATEGORIES=	editors print
MASTER_SITES=	ftp://ftp.texmacs.org/TeXmacs/tmftp/source/ \
		http://www.predatorlabs.net/dl/
DISTNAME=	TeXmacs-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG scientific text editor

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

OPTIONS_DEFINE=	FREETYPE GHOSTSCRIPT ICONV IMLIB2 PDF QT4
OPTIONS_DEFAULT=	FREETYPE GHOSTSCRIPT ICONV IMLIB2 QT4
PDF_DESC=	Experimental PDF renderer

DESKTOP_ENTRIES=	"TeXmacs" "${COMMENT}" \
			"${DATADIR}/misc/pixmaps/TeXmacs.xpm" "texmacs" \
			"Education;Science;" false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--with-freetype=linked
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

.if ${PORT_OPTIONS:MGHOSTSCRIPT}
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--with-gs=yes
.else
CONFIGURE_ARGS+=	--without-gs
.endif

.if ${PORT_OPTIONS:MICONV}
USE_ICONV=	yes
CONFIGURE_ARGS+=	--with-iconv="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

.if ${PORT_OPTIONS:MIMLIB2}
USE_EFL=	imlib2
CONFIGURE_ARGS+=	--with-imlib2
.else
CONFIGURE_ARGS+=	--without-imlib
.endif

.if ${PORT_OPTIONS:MPDF}
CONFIGURE_ARGS+=	--enable-pdf-renderer
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	gui moc_build qmake_build rcc uic_build
CONFIGURE_ARGS+=	--with-qt --enable-qtpipes
.else
CONFIGURE_ARGS+=	--disable-qt
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		 's|#!/bin/bash|#!/bin/sh|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete
	@${FIND} ${WRKSRC} -name \*.DS_Store -delete
	@${REINPLACE_CMD} -e 's|ICONV_LDFLAGS/-liconv|ICONV_LDFLAGS|' \
		${WRKSRC}/configure
	@ #fix for namespace clash with Qt3
	@${REINPLACE_CMD} -e 's|qdrawutil.h|qt4/Qt/qdrawutil.h|' \
		${WRKSRC}/src/Plugins/Qt/QTMStyle.cpp

post-install:
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${PREFIX}/libexec/TeXmacs
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.include <bsd.port.post.mk>
