# Ports collection makefile for:	aqmoney
# Date created:				April 15, 2003
# Whom:					Heiner Strauss <heiner@bilch.com>
#
# $FreeBSD$

PORTNAME=		aqmoney
PORTVERSION=		0.6.3
CATEGORIES=		finance
MASTER_SITES=	 	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manage your credit institute accounts using openhbci

LIB_DEPENDS=		openhbci.14:${PORTSDIR}/finance/openhbci

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
MAN1=			aqmoney.1
PLIST_FILES=		bin/aqmoney

.include <bsd.port.mk>
