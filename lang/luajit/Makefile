PORTNAME=	luajit
DISTVERSION=	2.1.0.20250728
CATEGORIES=	lang
DISTNAME=	LuaJIT-${DISTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Just-In-Time Compiler for Lua
WWW=		https://luajit.org/luajit.html

LICENSE=	MIT PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

IGNORE_riscv64=		fails to compile: lj_arch.h:73:2: No support for this architecture (yet)

USES=		compiler cpe gmake

CONFLICTS_INSTALL=	luajit-openresty

USE_LDCONFIG=	yes
MAKE_ARGS=	CC=${CC} CCOPT= CCOPT_x86= Q=

USE_GITHUB=	yes
GH_TUPLE=	LuaJIT:LuaJIT:871db2c

LUAJIT_VERSION=	2.1
LUAJIT_SOVERSION=	2.1.1753364724

PLIST_SUB+=	VERSION=${LUAJIT_VERSION} SOVERSION=${LUAJIT_SOVERSION}

post-install:
	${LN} -sf ${PORTNAME}-${LUAJIT_SOVERSION} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/etc/luajit.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
