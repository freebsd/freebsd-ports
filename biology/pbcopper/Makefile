# $FreeBSD$

PORTNAME=	pbcopper
DISTVERSION=	g20180413
PORTREVISION=	3
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Core C++ library for Pacific Biosciences tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		cmake compiler:c++14-lang
# Although there are a couple releases, git describe --tags does not work
# so we cannot use the usual USE_GITHUB tools here.
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	17ef457a0dbe1894a8d17af7ddba01a6261bf117

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include
	${MV} ${STAGEDIR}${PREFIX}/include/meson.build \
		${STAGEDIR}${PREFIX}/include/pbcopper

.include <bsd.port.mk>
