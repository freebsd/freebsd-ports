# New ports collection makefile for:	dnsflood
# Date created:				17.10.2003
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	dnsflood
PORTVERSION=	1.10
CATEGORIES=	dns
MASTER_SITES=	http://www.adotout.com/ \
		http://voodoo.oberon.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	krion@FreeBSD.org
COMMENT=	DNS flood detector

USE_SIZE=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/dns_flood_detector

pre-patch:
	${CP} ${WRKSRC}/makefiles/Makefile-FreeBSD ${WRKSRC}/Makefile

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dns_flood_detector ${PREFIX}/sbin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
