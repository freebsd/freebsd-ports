# Created by: Sergey A. Osokin <osa@FreeBSD.org>

PORTNAME=	luajit
DISTVERSION=	2.1.0.20220116
CATEGORIES=	lang
PKGNAMESUFFIX=	-devel
DISTNAME=	LuaJIT-${DISTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Just-In-Time Compiler for Lua

LICENSE=	MIT PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

IGNORE_riscv64=		fails to compile: lj_arch.h:73:2: No support for this architecture (yet)

CONFLICTS_INSTALL=	luajit luajit-openresty

USES=		cpe gmake
USE_LDCONFIG=	yes
MAKE_ARGS=	CC=${CC} CCOPT= CCOPT_x86= Q=

USE_GITHUB=	yes
GH_TUPLE=	LuaJIT:LuaJIT:4077f0c

LUAJIT_VERSION=	2.1.0-beta3
LUAJIT_SOVERSION=	2.1.0

PLIST_SUB+=	VERSION=${LUAJIT_VERSION} SOVERSION=${LUAJIT_SOVERSION}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*} || ${ARCH:Mmips*}
USE_GCC=yes
.endif

post-install:
	${LN} -sf ${PORTNAME}-${DISTVERSION} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/etc/luajit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
