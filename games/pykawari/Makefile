# Created by: UMENO Takashi
# $FreeBSD$

PORTNAME=	pykawari
PORTVERSION=	8.2.8
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/kawari/kawari/${PORTVERSION}
DISTNAME=	kawari-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real kawari8 module for ninix-aya

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	ninix:games/ninix-aya

BUILD_WRKSRC=	${WRKSRC}/build/src

USES=		gmake python:2.7 zip
MAKEFILE=	gcc.mak
MAKE_ARGS=	CXX="${CXX}" CFLAGS="${CXXFLAGS}" \
		PYTHONBASE="${PYTHONBASE}" PYTHON_VERSION="${PYTHON_VERSION}"

CFLAGS+=	-I. -DNDEBUG -I${PYTHON_INCLUDEDIR} -fPIC

DATADIR=	${PREFIX}/share/kawari

post-patch:
	@${REINPLACE_CMD} -e 's|shell python|shell ${PYTHON_CMD}|' \
		${BUILD_WRKSRC}/gcc.mak

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/ninix \
		${STAGEDIR}${DATADIR}/build
	(cd ${WRKSRC}/build/mach/freebsd && ${INSTALL_LIB} libshiori.so \
		${STAGEDIR}${PREFIX}/libexec/ninix/_kawari8.so)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} document \
		${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} license.txt readme.1st \
		${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/build && ${INSTALL_DATA} BUILD.TXT \
		${STAGEDIR}${DATADIR}/build)

.include <bsd.port.mk>
