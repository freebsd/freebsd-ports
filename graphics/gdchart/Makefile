# New ports collection makefile for:	gdchart
# Date created:         4 June 2001
# Whom:                 Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gdchart
PORTVERSION=	0.9.4b
CATEGORIES=	graphics
MASTER_SITES=	http://www.fred.net/brv/chart/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}0.94b

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

MAKEFILE=	makefile

do-install:
	${INSTALL_DATA}	${WRKSRC}/libgdchart.a ${PREFIX}/lib
	${INSTALL_DATA}	${WRKSRC}/gdchart.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdc.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdcpie.h ${PREFIX}/include

.if !defined(NOPORTDOCS)
post-install:
	@${INSTALL} -d -m 0755 ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp1.c ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp2.c ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/NOTES-092b.txt ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/NOTES-093b.txt ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/NOTES-094b.txt ${PREFIX}/share/doc/gdchart
	@${ECHO} "================================================================================"
	@${ECHO} "Have a look at the sample code and README(s) in ${PREFIX}/share/doc/${PORTNAME}."
	@${ECHO} "To compile gdc_samp1, try something like:"
	@${ECHO}
	@${ECHO} "gcc -I${PREFIX}/include -o gdc_samp1 gdc_samp1.c -L${PREFIX}/lib -lgdchart -lgd"
	@${ECHO}
	@${ECHO} "NB: gdchart will produce PNGs, not GIFs, as newer versions of gd stopped"
	@${ECHO} "supporting GIFs."
	@${ECHO} "================================================================================"
.endif

.include <bsd.port.mk>
