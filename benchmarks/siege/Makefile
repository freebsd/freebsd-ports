# New ports collection makefile for:	siege
# Date created:			Jun 2, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	siege
PORTVERSION=	2.56
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://sid.joedog.org/pub/siege/ \
		http://www.cus.org.uk/~dom/distfiles/siege/

MAINTAINER=	d.marks@student.umist.ac.uk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl=/usr --disable-shared
MAN1=	siege.1 siege.config.1 layingsiege.1 urls_txt.1 bombardment.1 \
	siege2csv.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/siege ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/utils/bombardment ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/utils/siege.config ${PREFIX}/bin
	@${MV} ${WRKSRC}/utils/siege2csv.pl ${WRKSRC}/utils/siege2csv
	${INSTALL_SCRIPT} ${WRKSRC}/utils/siege2csv ${PREFIX}/bin
.for F in bombardment.1 layingsiege.1 siege.1 siege.config.1 \
	siege2csv.1 urls_txt.1
	${INSTALL_MAN} ${WRKSRC}/doc/${F} ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
