# New ports collection makefile for:	ufmcontrol
# Date created:				7 December 2002
# Whom:					nivit@users.sourceforge.net
#
# $FreeBSD$

PORTNAME=		ufmcontrol-i18n
PORTVERSION=		0.2.3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:C/-i18n$//1}

MAINTAINER=		nivit@FreeBSD.org
COMMENT=		USB radio control utility

RUN_DEPENDS=		snack>=2.2.10_4:${PORTSDIR}/audio/snack

USE_LDCONFIG=		yes
USE_TCL=		yes
MAKE_ENV=		NO_PROFILE=yes

MAN1=			ufmcontrol.1
MANLANG=		"" it.ISO8859-1

.include <bsd.port.mk>
