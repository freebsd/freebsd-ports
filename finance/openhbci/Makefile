# Ports collection makefile for:	openhbci
# Date created:				Jan 3, 2003
# Whom:					Heiner Strauss <heiner@bilch.com>
#
# $FreeBSD$

PORTNAME=		openhbci
PORTVERSION=		0.9.4
CATEGORIES=		finance
MASTER_SITES=	 	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		heiner@bilch.com

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CXXFLAGS=-pedantic
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=		yes

.include <bsd.port.mk>
