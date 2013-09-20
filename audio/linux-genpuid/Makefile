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

USE_LINUX=		yes
NO_BUILD=		yes
IA32_BINARY_PORT=	yes
NO_STAGE=	yes

PLIST_FILES=	bin/genpuid bin/mipcore libexec/mipcore

do-install:
	${BRANDELF} -t Linux ${WRKDIR}/${PORTNAME}-${PORTVERSION}/genpuid
	${BRANDELF} -t Linux ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mipcore
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/genpuid ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mipcore ${PREFIX}/libexec
	${LN} -fhs ${PREFIX}/libexec/mipcore ${PREFIX}/bin/mipcore

.include <bsd.port.mk>
