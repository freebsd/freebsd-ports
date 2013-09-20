# Created by: krion
# $FreeBSD$

PORTNAME=	dnsflood
PORTVERSION=	1.20
CATEGORIES=	dns
MASTER_SITES=	http://www.adotout.com/ \
		http://mirrors.rit.edu/zi/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zi@FreeBSD.org
COMMENT=	DNS flood detector

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/dns_flood_detector_1.2

PLIST_FILES=	sbin/dns_flood_detector
USE_RC_SUBR=	dnsflood
PORTDOCS=	README

NO_STAGE=	yes
pre-patch:
	@${LN} -sf ${WRKSRC}/makefiles/Makefile-FreeBSD ${WRKSRC}/Makefile

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
