# New ports collection makefile for:	ding
# Date created:							5/25/2001
# Whom:									n@nectar.com
#
# $FreeBSD$
#

PORTNAME=	ding
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	german tk84
MASTER_SITES=	ftp://ftp.tu-chemnitz.de/pub/Local/urz/ding/old-releases/

MAINTAINER=	nectar@FreeBSD.ORG
COMMENT=	A German-English dictionary program for X windows/Unix

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		agrep:${PORTSDIR}/textproc/agrep

USE_X_PREFIX=	yes

do-build:
	${SED} -E -e '1,/^exec/ s!wish!wish8.4!' \
	  -e 's!/usr/share/dict/ger-eng.txt!${PREFIX}/share/ding/ger-eng.txt!' \
	  ${WRKSRC}/ding > ${WRKSRC}/dingX

do-install:
	${MKDIR} ${PREFIX}/share/ding
	${INSTALL_SCRIPT} ${WRKSRC}/dingX ${PREFIX}/bin/ding
	${INSTALL_DATA} ${WRKSRC}/ger-eng.txt ${PREFIX}/share/ding/ger-eng.txt

.include <bsd.port.mk>
