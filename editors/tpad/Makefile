# New ports collection makefile for:	tpad
# Date created:		10 November 2003
# Whom:			Antonio Bonifati <ant@monitor.deis.unical.it>
#
# $FreeBSD$
#

PORTNAME=	tpad
PORTVERSION=	1.0
CATEGORIES=	editors tcl84 tk84
MASTER_SITES=	http://monitor.deis.unical.it/ant/tpad/ \
		http://queen.rett.polimi.it/~ant/tcl/script/
DISTNAME=	${PORTNAME}-${PORTVERSION}.tcl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ant@monitor.deis.unical.it
COMMENT=	Win95/98 (TM) Notepad clone written in Tcl/Tk

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTFILES} ${PREFIX}/bin/tpad

.include <bsd.port.mk>
