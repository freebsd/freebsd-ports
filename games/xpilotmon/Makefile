# New ports collection makefile for:   xpilotmon
# Date created:        14 January 2002
# Whom:                Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		xpilotmon
PORTVERSION=		2.8
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.xpilot.org/pub/contrib/

MAINTAINER=		jylefort@brutele.be

RUN_DEPENDS=		wish8.4:${PORTSDIR}/x11-toolkits/tk84

ALL_TARGET=		xpilotmon
MAN6=			xpilotmon.6

post-patch:
	@${PERL} -pi -e "s/exec wish/exec wish8.4/" ${WRKSRC}/xpilotmon.org
	@${PERL} -pi -e "s/.\(INSTALL_DATA\)/${INSTALL_MAN}/" ${WRKSRC}/Makefile

.include <bsd.port.mk>
