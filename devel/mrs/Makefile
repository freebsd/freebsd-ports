PORTNAME=	mrs
DISTVERSION=	20221223
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	nfilardo@microsoft.com
COMMENT=	Brett Gutstein's CHERI Temporal Safety Malloc Revocation Shim
WWW=		https://github.com/ctsrd-cheri/mrs

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	aarch64c riscv64c

FLAVORS=	cherivoke cherivoke_stats \
		cornucopia cornucopia_stats \
		cornucopia_load cornucopia_load_stats
FLAVOR?=	cornucopia_load

USES=		cmake compiler:c++17-lang

PLIST_SUB=	PKGNAMESUFFIX=${PKGNAMESUFFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_PROJECT=	mrs
GH_TAGNAME=	78112657f9e636104d35254c5669da2d8e1baceb

ALL_TARGET=	mrs

CMAKE_ARGS+=	-DGIT_SHA1_OVERRIDE=${GH_TAGNAME}

.if !${FLAVOR:M*_ratio*}
CMAKE_ARGS+=	-DQUARANTINE_RATIO=4
.endif

.if ${FLAVOR:Mcherivoke*}
CMAKE_OFF+=	OFFLOAD_QUARANTINE
CMAKE_ARGS+=	-DCONCURRENT_REVOCATION_PASSES=0
.endif

.if ${FLAVOR:Mcornucopia*}
CMAKE_ON+=	OFFLOAD_QUARANTINE
CMAKE_ARGS+=	-DCONCURRENT_REVOCATION_PASSES=1
.endif

.if ${FLAVOR:M*_load*}
CMAKE_ON+=	LOAD_SIDE_REVOCATION
.endif

.if ${FLAVOR:M*_stats*}
CMAKE_ON+=	PRINT_CAPREVOKE PRINT_STATS
.endif

.if !target(do-install)
CMAKE_ARGS+=	-DCMAKE_INSTALL_LIBDIR:STRING=lib/mrs${PKGNAMESUFFIX}
do-install:
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/libmrs.so \
		${STAGEDIR}${PREFIX}/lib/libmrs${PKGNAMESUFFIX}.so
.endif

.include <bsd.port.mk>
