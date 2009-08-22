# ports collection makefile for:	thebridge
# Date created:		22 June 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	thebridge
PORTVERSION=	1.06
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/cqinet/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Echolink conference bridge

GNU_CONFIGURE=	yes

PORTDOCS=	README
USE_RC_SUBR=	tbd

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/addons/usermgmt.cgi ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/addons/README ${DATADIR}

.include <bsd.port.mk>
