# Created by: Lewis Thompson <purple@lewiz.net>
# $FreeBSD$

PORTNAME=	remind
PORTVERSION=	3.1.15
CATEGORIES=	deskutils
MASTER_SITES=	http://www.roaringpenguin.com/files/download/ \
		http://freebsd.unixfreunde.de/sources/
DISTNAME=	${PORTNAME}-03.01.15

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Sophisticated calendar and alarm program

LICENSE=	GPLv2

OPTIONS_DEFINE=	TCLTK

GNU_CONFIGURE=	yes
MAKE_ARGS=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

PLIST_FILES=	bin/rem \
		bin/rem2ps \
		bin/remind \
		man/man1/rem.1.gz \
		man/man1/rem2ps.1.gz \
		man/man1/remind.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCLTK}
USES=		tk
RUN_DEPENDS+=	dtplite:devel/tcllib
PLIST_FILES+=	bin/cm2rem.tcl bin/tkremind
.endif

post-patch:
# This seems more than a little ugly.
.if defined(LAT_DEG)
	@${REINPLACE_CMD} -e 's#LAT_DEG 45#LAT_DEG ${LAT_DEG}#' ${WRKSRC}/src/custom.h
.endif
.if defined(LAT_MIN)
	@${REINPLACE_CMD} -e 's#LAT_MIN 24#LAT_MIN ${LAT_MIN}#' ${WRKSRC}/src/custom.h
.endif
.if defined(LAT_SEC)
	@${REINPLACE_CMD} -e 's#LAT_SEC  0#LAT_SEC ${LAT_SEC}#' ${WRKSRC}/src/custom.h
.endif
.if defined(LON_DEG)
	@${REINPLACE_CMD} -e 's#LON_DEG 75#LON_DEG ${LON_DEG}#' ${WRKSRC}/src/custom.h
.endif
.if defined(LON_MIN)
	@${REINPLACE_CMD} -e 's#LON_MIN 39#LON_MIN ${LON_MIN}#' ${WRKSRC}/src/custom.h
.endif
.if defined(LON_SEC)
	@${REINPLACE_CMD} -e 's#LON_SEC  0#LON_SEC ${LON_SEC}#' ${WRKSRC}/src/custom.h
.endif
.if defined(LOCATION)
	@${REINPLACE_CMD} -e 's#Ottawa#${LOCATION}#' ${WRKSRC}/src/custom.h
.endif
.if defined(A4)
	@${REINPLACE_CMD} -e 's#"Letter", 612, 792#"A4", 595, 842#' ${WRKSRC}/src/custom.h
.endif
.if ${PORT_OPTIONS:MTCLTK}
	@${REINPLACE_CMD} -e 's,wish,${WISH},' ${WRKSRC}/scripts/tkremind
	@${REINPLACE_CMD} -e 's,tclsh,${TCLSH},' ${WRKSRC}/scripts/cm2rem.tcl
.endif

do-install:
.for i in rem2ps remind
	${INSTALL_PROGRAM} ${WRKSRC}/src/${i} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${i}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/rem.1 ${STAGEDIR}${PREFIX}/man/man1
	${LN} -sf ${PREFIX}/bin/remind ${STAGEDIR}${PREFIX}/bin/rem
.if ${PORT_OPTIONS:MTCLTK}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/cm2rem.tcl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/tkremind ${STAGEDIR}${PREFIX}/bin
.for i in cm2rem tkremind
	${INSTALL_MAN} ${WRKSRC}/man/${i}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor
.endif

.include <bsd.port.mk>
