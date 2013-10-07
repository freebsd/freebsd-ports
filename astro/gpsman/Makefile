# Created by: David Wolfskill
# $FreeBSD$

PORTNAME=	gpsman
PORTVERSION=	6.4.4.2
CATEGORIES=	astro tk geography
MASTER_SITES=	SF/${PORTNAME}/distrib
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@catwhisker.org
COMMENT=	A Tcl/Tk-based GPS management utility

OPTIONS_DEFINE=	DOCS

USES+=		tk:wrapper,run

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GPSMANDIR=	${PREFIX}/lib/${PORTNAME}
PLIST_SUB+=	GPSMANDIR=${GPSMANDIR:S/${PREFIX}\///}
NO_BUILD=	yes
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800045
GPSMAN_DEFAULT_PORT?=	/dev/cuad0
.else
GPSMAN_DEFAULT_PORT?=	/dev/cuau0
.endif

.if ${PORT_OPTIONS:MDOCS}
SUB_FILES=	pkg-message
.endif

post-patch:
	@${REINPLACE_CMD} "s|/dev/ttyS0|${GPSMAN_DEFAULT_PORT}|" \
 		${WRKSRC}/util/exerciser.tcl \
		${WRKSRC}/manual/html/info/l_realtime.doc.txt \
		${WRKSRC}/gpsman.tcl
	@${REINPLACE_CMD} -e "s:%%WISH%%:${WISH}:; s:%%GPSMANDIR%%:${GPSMANDIR}:g" ${WRKSRC}/gpsman.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gpsman.tcl ${STAGEDIR}${PREFIX}/bin/gpsman
	${INSTALL_MAN} ${WRKSRC}/man/man1/gpsman.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${GPSMANDIR}/gmsrc/gmicons ${STAGEDIR}${GPSMANDIR}/util
	${INSTALL_DATA} ${WRKSRC}/gmsrc/*.tcl ${STAGEDIR}${GPSMANDIR}/gmsrc
	${INSTALL_DATA} ${WRKSRC}/gmsrc/gmicons/* ${STAGEDIR}${GPSMANDIR}/gmsrc/gmicons
	${INSTALL_DATA} ${WRKSRC}/util/*.sh ${STAGEDIR}${GPSMANDIR}/util
	${INSTALL_DATA} ${WRKSRC}/util/*.tcl ${STAGEDIR}${GPSMANDIR}/util
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html/info
	${INSTALL_DATA} ${WRKSRC}/manual/*.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/html/*.html ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/manual/html/*.gif ${STAGEDIR}${DOCSDIR}/html
.for i in gif txt ps
	${INSTALL_DATA} ${WRKSRC}/manual/html/info/*.${i} ${STAGEDIR}${DOCSDIR}/html/info
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
