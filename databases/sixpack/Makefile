# New ports collection makefile for:		sixpack
# Date created:					July 10th 2001
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	sixpack
PORTVERSION=	0.99.001216
CATEGORIES=	databases
MASTER_SITES=	http://www.santafe.edu/~dirk/sixpack/Download/

MAINTAINER=	ports@FreeBSD.org

BROKEN=		"Does not package correctly"

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget \
		ptksh:${PORTSDIR}/x11-toolkits/p5-Tk

NO_BUILD=	yes

USE_PERL5=	yes

#MAN8=		porteasy.8

post-extract:
	(cd ${WRKSRC} && ${TAR} zxf bp-0.2.97.tar.gz)

do-configure:
	${PERL} -p -i -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/install
	${PERL} -p -i -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/install
	${PERL} -p -i -e 's|%%DOCSDIR%%|${DOCSDIR}|' ${WRKSRC}/install

do-install:
	(cd ${WRKSRC} && ${SH} install with-bp with-mod)

.include <bsd.port.mk>
