# New ports collection makefile for:	siege
# Date created:			Jun 2, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	siege
PORTVERSION=	2.59
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://sid.joedog.org/pub/siege/ \
		http://www.cus.org.uk/~dom/distfiles/siege/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A http regression testing and benchmarking utility

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE} --disable-shared

MAN1=		siege.1 siege.config.1 layingsiege.1 urls_txt.1 bombardment.1 \
		siege2csv.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/siege ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/utils/bombardment ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/utils/siege2csv.pl ${PREFIX}/bin/siege2csv
.for F in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/doc/${F} ${MAN1PREFIX}/man/man1
.endfor
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/siegerc ${DATADIR}
	@${SED} -e "s,%%DATADIR%%,${DATADIR}," ${FILESDIR}/siege.config.in > ${PREFIX}/bin/siege.config
	@${CHMOD} 555 ${PREFIX}/bin/siege.config

.include <bsd.port.mk>
