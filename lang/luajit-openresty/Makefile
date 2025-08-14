PORTNAME=	luajit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1-20250529
PORTREVISION=	1
CATEGORIES=	lang
PKGNAMESUFFIX=	-openresty

PATCH_SITES=	https://github.com/openresty/luajit2/commit/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Just-In-Time Compiler for Lua (OpenResty branch)
WWW=		https://github.com/openresty/luajit2

LICENSE=	MIT PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

IGNORE_riscv64=		fails to compile: lj_arch.h:73:2: No support for this architecture (yet)

USES=		cpe gmake

CONFLICTS_INSTALL=	luajit

USE_LDCONFIG=	yes
MAKE_ARGS=	CC=${CC} Q=

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	luajit2

LUAJIT_VERSION=	2.1
LUAJIT_SOVERSION=	2.1.1748495995

PLIST_SUB+=	VERSION=${LUAJIT_VERSION} SOVERSION=${LUAJIT_SOVERSION}

.include <bsd.port.options.mk>

.if ${ARCH:Mmips*}
USE_GCC=yes
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${LUAJIT_SOVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libluajit-5.1.so.${LUAJIT_SOVERSION}
	${LN} -sf ${PORTNAME}-${LUAJIT_SOVERSION} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/etc/luajit.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
