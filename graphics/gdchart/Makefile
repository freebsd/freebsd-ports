# New ports collection makefile for:	gdchart
# Date created:         4 June 2001
# Whom:                 Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gdchart
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.fred.net/brv/chart/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION}dev

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA}	${WRKSRC}/libgdchart.a ${PREFIX}/lib
	${INSTALL_DATA}	${WRKSRC}/gdchart.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdc.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdcpie.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gifencode.h ${PREFIX}/include

.if !defined(NOPORTDOCS)
post-install:
	@${INSTALL} -d -m 0755 ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp1.c ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp2.c ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_pie_samp.c ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gdchart
	@${ECHO} "================================================================================"
	@${ECHO} "Have a look at the sample code and README in ${PREFIX}/share/doc/${PORTNAME}."
	@${ECHO} "To compile gdc_samp1, try something like:"
	@${ECHO}
	@${ECHO} "gcc -I${PREFIX}/include -o gdc_samp1 gdc_samp1.c -L${PREFIX}/lib -lgdchart -lgd"
	@${ECHO} "================================================================================"
.endif

.include <bsd.port.mk>
