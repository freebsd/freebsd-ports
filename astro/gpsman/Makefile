# New ports collection makefile for:	gpsman
# Date created:		26 November 2001
# Whom:			David Wolfskill
#
# $FreeBSD$
#

PORTNAME=	gpsman
PORTVERSION=	6.2.1
CATEGORIES=	astro tk84
MASTER_SITES=	http://www.ncc.up.pt/gpsman/gpsmanhtml/
MASTER_SITE_SUBDIR=	science/cartography
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@catwhisker.org
COMMENT=	A Tcl/Tk-based GPS management utility

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

# MAN1=		gpsman.1
# MANCOMPRESSED=	yes

pre-install:
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/gpsman.tcl

do-install:
	@${MKDIR} ${PREFIX}/share/gpsman
	@${MKDIR} ${PREFIX}/share/gpsman/gmsrc
	${INSTALL_DATA} ${WRKSRC}/gmsrc/*.tcl ${PREFIX}/share/gpsman/gmsrc
	@${MKDIR} ${PREFIX}/share/gpsman/gmsrc/gmicons
	${INSTALL_DATA} ${WRKSRC}/gmsrc/gmicons/* ${PREFIX}/share/gpsman/gmsrc/gmicons
	@${MKDIR} ${PREFIX}/share/gpsman/util
	${INSTALL_DATA} ${WRKSRC}/util/*.sh ${PREFIX}/share/gpsman/util
	${INSTALL_DATA} ${WRKSRC}/util/*.tcl ${PREFIX}/share/gpsman/util
	${INSTALL_SCRIPT} ${WRKSRC}/gpsman.tcl ${PREFIX}/share/gpsman
	${LN} -fs ${PREFIX}/share/gpsman/gpsman.tcl ${PREFIX}/bin/gpsman
#	${INSTALL_MAN} ${WRKSRC}/gpsman.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gpsman
	${INSTALL_DATA} ${WRKSRC}/manual/*.pdf ${PREFIX}/share/doc/gpsman
	@${MKDIR} ${PREFIX}/share/doc/gpsman/html
	${INSTALL_DATA} ${WRKSRC}/manual/html/*.html ${PREFIX}/share/doc/gpsman/html
	${RM} ${PREFIX}/share/doc/gpsman/html/index.html
	${LN} ${PREFIX}/share/doc/gpsman/html/GPSMandoc.html ${PREFIX}/share/doc/gpsman/html/index.html
	${INSTALL_DATA} ${WRKSRC}/manual/html/*.gif ${PREFIX}/share/doc/gpsman/html
	@${MKDIR} ${PREFIX}/share/doc/gpsman/html/info
	${INSTALL_DATA} ${WRKSRC}/manual/html/info/*.gif ${PREFIX}/share/doc/gpsman/html/info
	${INSTALL_DATA} ${WRKSRC}/manual/html/info/*.txt ${PREFIX}/share/doc/gpsman/html/info
	${RM} ${PREFIX}/share/doc/gpsman/html/info/GPL.txt
	${INSTALL_DATA} ${WRKSRC}/manual/html/info/*.ps ${PREFIX}/share/doc/gpsman/html/info
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" pkg-message
.endif

.include <bsd.port.mk>
