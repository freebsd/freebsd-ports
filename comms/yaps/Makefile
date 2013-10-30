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

MAN1=		yaps.1
PLIST_FILES=	bin/yaps etc/yaps.rc.sample
PORTDOCS=	yaps.doc yaps.html
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/yaps.rc ${PREFIX}/etc/yaps.rc.sample
	${INSTALL_MAN} ${WRKSRC}/yaps.1 ${PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/yaps.doc ${WRKSRC}/yaps.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
