# ports collection makefile for:	thebridge
# Date created:		22 June 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	thebridge
PORTVERSION=	0.72
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cqinet
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio Echolink conference bridge

GNU_CONFIGURE=	yes

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/FreeBSD/tbd.sh
	@${MV} ${WRKSRC}/tbd.conf ${WRKSRC}/tbd.conf.sample

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/FreeBSD/tbd.sh ${PREFIX}/etc/rc.d/tbd.sh.sample

.include <bsd.port.mk>
