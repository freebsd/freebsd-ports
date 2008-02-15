# ports collection makefile for:	thebridge
# Date created:		22 June 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	thebridge
PORTVERSION=	0.89
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cqinet
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

.include <bsd.port.mk>
