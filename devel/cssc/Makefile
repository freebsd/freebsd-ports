# Created by: Oliver Fromme
# $FreeBSD$

PORTNAME=	cssc
PORTVERSION=	1.4.0
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	CSSC-${PORTVERSION}

MAINTAINER=	oliver@fromme.com
COMMENT=	Workalike for the source code control system SCCS

LICENSE=	GPLv3

BROKEN_mips=		fails to compile: ../gl/lib/unistd.h:135:3: "Please include config.h first."
BROKEN_mips64=		fails to compile: ../gl/lib/unistd.h:135:3: "Please include config.h first."
BROKEN_powerpc64=	does not build: undefined reference to fmax

GNU_CONFIGURE=	yes
INFO=		cssc
USE_GCC=	any

OPTIONS_DEFINE=			BINARY
OPTIONS_DEFAULT=		BINARY
BINARY_DESC=			Support binary SCCS files (Solaris interoperability)
BINARY_CONFIGURE_ENABLE=	binary

.include <bsd.port.mk>
