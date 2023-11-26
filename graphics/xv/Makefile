PORTNAME=	xv
PORTVERSION=	4.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES+=	graphics
DIST_SUBDIR=	${PORTNAME}

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	X11 program that displays images of various formats
WWW=		http://www.trilon.com/xv/

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libjasper.so:graphics/jasper \
		libwebp.so:graphics/webp

USES=		cpe localbase cmake jpeg xorg
USE_XORG=	xext x11 xt ice sm

USE_GITHUB=	yes
GH_ACCOUNT=	jasper-software

CPE_VENDOR=	xv_project

OPTIONS_DEFINE=	M17N DOCS
M17N_DESC=	build with Multilingualization support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MM17N}
CFLAGS+=	-DTV_MULTILINGUAL
DESCR=	${FILESDIR}/pkg-descr
CONFLICTS_INSTALL=	xv
.else
CONFLICTS_INSTALL=	xv-m17n
.endif

XV_DOCS=	README.md src/docs/help

do-install-DOCS-on:
.for i in ${XV_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

do-install-DOCS-off:
	${RM} -fr ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
