# New ports collection makefile for:	ding
# Date created:							5/25/2001
# Whom:									n@nectar.com
#
# $FreeBSD$
#

PORTNAME=	ding
PORTVERSION=	1.3
CATEGORIES=	german tk84
MASTER_SITES=	ftp://ftp.tu-chemnitz.de/pub/Local/urz/ding/

MAINTAINER=	nectar@FreeBSD.ORG
COMMENT=	A German-English dictionary program for X windows/Unix

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		agrep:${PORTSDIR}/textproc/agrep

MAN1=		ding.1
USE_X_PREFIX=	yes

do-build:
	${SED} -E -e '1,/^exec/ s!wish!wish8.4!' \
	  -e 's!/usr/share/dict/ger-eng.txt!${PREFIX}/share/ding/ger-eng.txt!' \
	  ${WRKSRC}/ding > ${WRKSRC}/dingX

do-install:
	${MKDIR} ${PREFIX}/share/ding
	${INSTALL_SCRIPT} ${WRKSRC}/dingX ${PREFIX}/bin/ding
	${INSTALL_DATA} ${WRKSRC}/ger-eng.txt ${PREFIX}/share/ding/ger-eng.txt
	${INSTALL_DATA} ${WRKSRC}/ding.png ${PREFIX}/share/ding/ding.png
	${INSTALL_MAN} ${WRKSRC}/ding.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
