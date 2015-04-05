# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTNAME=	genpuid
PORTVERSION=	1.4
CATEGORIES=	audio linux
MASTER_SITES=	https://secure.musicip.com/dns/files/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}_linux_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application for generating MusicIP puids

BROKEN=		Unfetchable
USE_LINUX=		yes
NO_BUILD=		yes
IA32_BINARY_PORT=	yes

PLIST_FILES=	bin/genpuid bin/mipcore libexec/mipcore

do-install:
	${BRANDELF} -t Linux ${WRKDIR}/${PORTNAME}-${PORTVERSION}/genpuid
	${BRANDELF} -t Linux ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mipcore
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/genpuid ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mipcore ${STAGEDIR}${PREFIX}/libexec
	${LN} -fhs ${PREFIX}/libexec/mipcore ${STAGEDIR}${PREFIX}/bin/mipcore

.include <bsd.port.mk>
