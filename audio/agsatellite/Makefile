# New ports collection makefile for:	audiogalaxy satellite
# Date created:				Thu Aug 30 15:59:04 GMT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	agsatellite
PORTVERSION=	0.520
PORTREVISION=	1
CATEGORIES=	audio net linux
MASTER_SITES=	http://www.audiogalaxy.com/downloads/
DISTNAME=	AGSatellite${PORTVERSION:S/.//}-glibc21

MAINTAINER=	lioux@FreeBSD.org

WRKSRC=	${WRKDIR}/${DISTNAME:C/-.*//}

USE_LINUX=	yes
NO_BUILD=	yes
STRIP=
RESTRICTED=	no response from developer on licensing issues

DOCS=	german_readme.txt license.txt readme.txt

BRANDELF=	/usr/bin/brandelf

post-patch:
	@${PERL} -pi -e "s|||" ${WRKSRC}/*.txt
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh

pre-install:
	@${BRANDELF} -t Linux ${WRKSRC}/AGSatellite

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/AGSatellite ${PREFIX}/bin/AGSatellite-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/AGSatellite
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
