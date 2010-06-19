# New ports collection makefile for:	siege
# Date created:			Jun 2, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	siege
PORTVERSION=	2.69
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://sid.joedog.org/pub/siege/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A http regression testing and benchmarking utility

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE} --disable-shared

MAN1=		siege.1 siege.config.1 bombardment.1 siege2csv.1
MAN5=		urls_txt.5
MAN7=		layingsiege.7

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/siege ${PREFIX}/bin/
	@${INSTALL_SCRIPT} ${WRKSRC}/utils/bombardment ${PREFIX}/bin/
	@${INSTALL_SCRIPT} ${WRKSRC}/utils/siege2csv.pl ${PREFIX}/bin/siege2csv
	@${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/doc/,} ${MAN1PREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/doc/${MAN5} ${MAN1PREFIX}/man/man5/
	@${INSTALL_MAN} ${WRKSRC}/doc/${MAN7} ${MAN1PREFIX}/man/man7/
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/siegerc ${DATADIR}/
	@${SED} -e "s,%%DATADIR%%,${DATADIR}," ${FILESDIR}/siege.config.in > ${PREFIX}/bin/siege.config
	@${CHMOD} 555 ${PREFIX}/bin/siege.config

.include <bsd.port.mk>
