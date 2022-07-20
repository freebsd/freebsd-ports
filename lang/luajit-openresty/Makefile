PORTNAME=	luajit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1-20220411
CATEGORIES=	lang
PKGNAMESUFFIX=	-openresty

PATCH_SITES=	https://github.com/openresty/luajit2/commit/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Just-In-Time Compiler for Lua (OpenResty branch)

LICENSE=	MIT PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

IGNORE_riscv64=		fails to compile: lj_arch.h:73:2: No support for this architecture (yet)

USES=		cpe gmake

CONFLICTS_INSTALL=	luajit luajit-devel

USE_LDCONFIG=	yes
MAKE_ARGS=	CC=${CC} Q=

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	luajit2

LUAJIT_VERSION=	2.1.0-beta3
LUAJIT_SOVERSION=	2.1.0

PLIST_SUB+=	VERSION=${LUAJIT_VERSION} SOVERSION=${LUAJIT_SOVERSION}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*} || ${ARCH:Mmips*}
USE_GCC=yes
.endif

post-install:
	${LN} -sf ${PORTNAME}-${LUAJIT_VERSION} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/etc/luajit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
