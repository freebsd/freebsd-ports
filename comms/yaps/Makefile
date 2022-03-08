# Created by: se

PORTNAME=	yaps
PORTVERSION=	0.96
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	SUNSITE/apps/serialcomm/machines

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Pager Software: send messages to pager (SMS, TAP, ...)

BROKEN=		Service providers are no longer available
DEPRECATED=	Service providers are no longer around and/or are no longer providing this service
EXPIRATION_DATE=2022-03-31

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

USES=		gmake

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaps ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/yaps.rc ${STAGEDIR}${PREFIX}/etc/yaps.rc.sample
	${INSTALL_MAN} ${WRKSRC}/yaps.1 ${STAGEDIR}${PREFIX}/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/yaps.doc ${WRKSRC}/yaps.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
