# Created by: se
# $FreeBSD$

PORTNAME=	yaps
PORTVERSION=	0.96
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/serialcomm/machines

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Pager Software: send messages to pager (SMS, TAP, ...)

LICENSE=	GPLv2

USES=		gmake

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/yaps.rc ${STAGEDIR}${PREFIX}/etc/yaps.rc.sample
	${INSTALL_MAN} ${WRKSRC}/yaps.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/yaps.doc ${WRKSRC}/yaps.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
