# Created by: jagapen@home.com
# $FreeBSD$

PORTNAME=	ffcall
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNUSTEP/libs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Foreign function call libraries

LICENSE=	GPLv2

BROKEN_aarch64=		Does not build: No rule to make target avcall-aarch64.lo
BROKEN_armv6=		Does not build: error: invalid instruction
BROKEN_mips64==		Does not build: error: duplicate member anum
BROKEN_powerpc64=	Does not build

GNU_CONFIGURE=	yes
USES=		gmake libtool

CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-fPIC

.include <bsd.port.mk>
