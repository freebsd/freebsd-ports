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

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/olirc ${PREFIX}/bin

.include <bsd.port.mk>
