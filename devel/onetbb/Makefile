# Created by: Arun Sharma <arun@sharma-home.net>
# $FreeBSD$

PORTNAME=	onetbb
PORTVERSION=	2021.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Library that provides thread building blocks

LICENSE=	APACHE20

LIB_DEPENDS=	libhwloc.so.15:devel/hwloc2

USES=		cmake compiler:c++11-lang tar:tgz

CMAKE_ARGS+=	-DTBB_STRICT:BOOL=FALSE

CONFLICTS=	tbb-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	oneapi-src
GH_PROJECT=	oneTBB

SUB_FILES=	onetbb.pc
SUB_LIST=	prefix="${PREFIX}" \
		name="${PORTNAME}" \
		description="${COMMENT}" \
		version="${PORTVERSION}"

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-install:
	${INSTALL_DATA} ${WRKDIR}/onetbb.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.post.mk>
