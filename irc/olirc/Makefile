# New ports collection makefile for:	olirc
# Date created:		Sat Jul 24 03:04:46 MET DST 1999
# Whom:			Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	olirc
PORTVERSION=	0.0.37
CATEGORIES=	irc
MASTER_SITES=	http://olirc.hexanet.fr/

MAINTAINER=	nox@jelal.kn-bremen.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/olirc ${PREFIX}/bin

.include <bsd.port.mk>
