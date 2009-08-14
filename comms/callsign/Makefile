# New ports collection makefile for:	callsign-bin
# Date created:        31 July 2009
# Whom:                Rick Elrod <codeblock@eighthbit.net>
#
# $FreeBSD$
#

PORTNAME=	callsign
PORTVERSION=	1.0.1
CATEGORIES=	comms net hamradio
MASTER_SITES=	RF
DISTNAME=	callsign-${PORTVERSION}

MAINTAINER=	codeblock@eighthbit.net
COMMENT=	An amateur radio callsign lookup command

RUN_DEPENDS=	rubygem-callsign>=0:${PORTSDIR}/comms/rubygem-callsign

WRKSRC=		${WRKDIR}
NO_BUILD=	YES
PLIST_FILES=	bin/callsign

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/callsign ${LOCALBASE}/bin/

.include <bsd.port.mk>
