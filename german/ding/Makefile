# New ports collection makefile for:	ding
# Date created:							5/25/2001
# Whom:									n@nectar.com
#
# $FreeBSD$
#

PORTNAME=		ding
PORTVERSION=	1.2
CATEGORIES=		german
MASTER_SITES=	http://cgi.tu-chemnitz.de/ftp-home/pub/Local/urz/ding/ \
				ftp://ftp.tu-chemnitz.de/pub/Local/urz/ding/

MAINTAINER=		nectar@FreeBSD.ORG

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83 \
				agrep:${PORTSDIR}/textproc/agrep

USE_X_PREFIX=	yes

do-build:
	${SED} -E -e '1,/^exec/ s!wish!wish8.3!' \
	  -e 's!/usr/share/dict/ger-eng.txt!${PREFIX}/share/ding/ger-eng.txt!' \
	  ${WRKSRC}/ding > ${WRKSRC}/dingX

do-install:
	${MKDIR} ${PREFIX}/share/ding
	${INSTALL_SCRIPT} ${WRKSRC}/dingX ${PREFIX}/bin/ding
	${INSTALL_DATA} ${WRKSRC}/ger-eng.txt ${PREFIX}/share/ding/ger-eng.txt

.include <bsd.port.mk>
