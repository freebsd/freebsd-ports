# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTNAME=	genpuid
PORTVERSION=	1.4
CATEGORIES=	audio linux
MASTER_SITES=	http://www.spicefly.com/files/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}_linux_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application for generating MusicIP puids

USES=		linux tar:tgz
BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

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
