# New ports collection makefile for:	remind
# Date created:				10 April 2004
# Whom:					Lewis Thompson <purple@lewiz.net>
#
# $FreeBSD$
#

PORTNAME=	remind
PORTVERSION=	3.0.22
CATEGORIES=	deskutils
MASTER_SITES=	http://www.roaringpenguin.com/products/${PORTNAME}/
DISTNAME=	${PORTNAME}-03.00.22

MAINTAINER=	purple@lewiz.net
COMMENT=	Sophisticated calendar and alarm program

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		kall.1 rem.1 rem2ps.1 remind.1 tkremind.1 cm2rem.1

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

.include <bsd.port.mk>
