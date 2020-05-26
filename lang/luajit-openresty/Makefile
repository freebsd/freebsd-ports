# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	luajit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1-20200102
CATEGORIES=	lang
PKGNAMESUFFIX=	-openresty

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Just-In-Time Compiler for Lua (OpenResty branch)

LICENSE=	MIT PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BROKEN_powerpc64=	fails to build: gmake[2]: *** No rule to make target 'vm_ppc64.dasc', needed by 'host/buildvm_arch.h'.

USES=		gmake

CONFLICTS_INSTALL=	luajit

USE_LDCONFIG=	yes
MAKE_ARGS=	CC=${CC}

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
