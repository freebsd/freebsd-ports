# Ports collection makefile for:	aqmoney
# Date created:				April 15, 2003
# Whom:					Heiner Strauss <heiner@bilch.com>
#
# $FreeBSD$

PORTNAME=		aqmoney
PORTVERSION=		0.6.2
CATEGORIES=		finance
MASTER_SITES=	 	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	heiner@bilch.com
COMMENT=	AqMoney uses openhbci to manage your credit institute accounts

LIB_DEPENDS=		openhbci.13:${PORTSDIR}/finance/openhbci

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
MAN1=			aqmoney.1

.include <bsd.port.mk>
