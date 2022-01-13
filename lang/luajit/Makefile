# Created by: Sergey A. Osokin <osa@FreeBSD.org>

PORTNAME=	luajit
DISTVERSION=	2.0.5
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	https://luajit.org/download/
DISTNAME=	LuaJIT-${DISTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Just-In-Time Compiler for Lua

OPTIONS_DEFINE=	PTHREAD
PTHREAD_DESC=	with pthread support

LICENSE=	MIT PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

IGNORE_aarch64=		fails to compile: lj_arch.h:55:2: No support for this architecture (yet)
IGNORE_powerpc64=	fails to compile: lj_arch.h:346:2: No support for PowerPC 64 bit mode
IGNORE_riscv64=		fails to compile: lj_arch.h:55:2: No support for this architecture (yet)

CONFLICTS_INSTALL=	luajit-devel luajit-openresty

WRKSRC=		${WRKDIR}/LuaJIT-${DISTVERSION}
USES=		cpe gmake
USE_LDCONFIG=	yes
MAKE_ARGS=	CC=${CC} CCOPT= CCOPT_x86=

PLIST_SUB+=	VERSION=${DISTVERSION}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*} || ${ARCH:Mmips*} || ${ARCH:Msparc*}
USE_GCC=yes
.endif

.if ${PORT_OPTIONS:MPTHREAD}
LDFLAGS+=	-lm -pthread
.endif

post-install:
	${LN} -sf ${PORTNAME}-${DISTVERSION} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/etc/luajit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
