# New ports collection makefile for:	wmQStat
# Date created:				25 Apr 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmqstat
PORTVERSION=	0.0.4
PORTREVISION=	2
CATEGORIES=	games windowmaker
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/wmQStat%20${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A dockapp for monitoring of various Internet game servers

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat

USE_XORG=	xpm x11 xext
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
