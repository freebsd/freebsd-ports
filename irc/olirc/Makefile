# New ports collection makefile for:	olirc
# Date created:		Sat Jul 24 03:04:46 MET DST 1999
# Whom:			Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	olirc
PORTVERSION=	0.0.38.a3.2
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://olirc.sourceforge.net/
DISTNAME=	olirc-0.0.38-alpha-3.2

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	A small irc client using GTK+

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/olirc ${PREFIX}/bin

.include <bsd.port.mk>
