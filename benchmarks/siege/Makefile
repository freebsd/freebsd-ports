# New ports collection makefile for:	siege
# Date created:			Jun 2, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	siege
PORTVERSION=	2.05
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.armstrong.com/pub/siege/ \
		http://nerf-herder.net/siege/

MAINTAINER=	markp@FreeBSD.org

USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--with-ssl=/usr --disable-shared
MAN1=	siege.1 siege.config.1 scout.1 layingsiege.1 urls_txt.1 bombardment.1 \
	siege2csv.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/siege/siege ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/scout/scout ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/utils/bombardment ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/utils/siege.config ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/utils/siege2csv.pl ${PREFIX}/bin/siege2csv
.for F in bombardment.1 layingsiege.1 scout.1 siege.1 siege.config.1 \
		siege2csv.1 urls_txt.1
	${INSTALL_MAN} ${WRKSRC}/doc/${F} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/doc/manual.html \
		${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
