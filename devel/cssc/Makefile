# Created by: Oliver Fromme
# $FreeBSD$

PORTNAME=	cssc
PORTVERSION=	1.4.0
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	CSSC-${PORTVERSION}

MAINTAINER=	oliver@fromme.com
COMMENT=	Workalike for the source code control system SCCS

LICENSE=	GPLv3

BROKEN_powerpc64=	does not build: undefined reference to fmax

GNU_CONFIGURE=	yes
INFO=		cssc
USE_GCC=	any

OPTIONS_DEFINE=			BINARY
OPTIONS_DEFAULT=		BINARY
BINARY_DESC=			Support binary SCCS files (Solaris interoperability)
BINARY_CONFIGURE_ENABLE=	binary

.include <bsd.port.mk>
