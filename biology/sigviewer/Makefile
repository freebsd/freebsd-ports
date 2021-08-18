PORTNAME=	sigviewer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.4-13
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gf62f8d9
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Viewing application for biosignals

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiosig.so:biology/biosig \
		libxdf.so:misc/libxdf

USES=		gl qmake qt:5
USE_QT=		core gui widgets xml qmake_build buildtools_build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	cbrnr

CXXFLAGS+=	-D__LITTLE_ENDIAN

PLIST_FILES=	bin/sigviewer

do-install: # see https://github.com/cbrnr/sigviewer/issues/130
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/release/sigviewer ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
