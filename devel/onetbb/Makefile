# Created by: Arun Sharma <arun@sharma-home.net>

PORTNAME=	onetbb
PORTVERSION=	2021.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Library that provides thread building blocks

LICENSE=	APACHE20

LIB_DEPENDS=	libhwloc.so.15:devel/hwloc2

USES=		cmake compiler:c++11-lang tar:tgz

CMAKE_ARGS+=	-DTBB_STRICT:BOOL=FALSE \
		-DCMAKE_INSTALL_DOCDIR:PATH="${DOCSDIR}" \
		-DCMAKE_HWLOC_2_4_LIBRARY_PATH:PATH="${LOCALBASE}/lib/libhwloc.so" \
		-DCMAKE_HWLOC_2_4_INCLUDE_PATH:PATH="${LOCALBASE}/include"

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

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == powerpc
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src_tbb_tools__api_ittnotify__config.h
.endif

post-install:
	${INSTALL_DATA} ${WRKDIR}/onetbb.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.post.mk>
