# New ports collection makefile for:	frei0r-plugins
# Date created:				29 June 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
PKGNAMESUFFIX=	-plugins
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

COMMENT=	Frei0r meta-port

# Required in order to avoid conflicts with graphics/frei0r's OPTIONS.
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

RUN_DEPENDS=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r

MASTERDIR=	${.CURDIR}/../frei0r
NO_BUILD=	yes
PLIST=		${WRKDIR}/PLIST

BUILDING_FREI0R_METAPORT=	yes

OPTIONS=	GAVL "Install gavl plugins" on \
		OPENCV "Install OpenCV plugins" on

.include "${MASTERDIR}/Makefile"

.include <bsd.port.options.mk>

.if !defined(WITHOUT_GAVL)
RUN_DEPENDS+=	${LOCALBASE}/lib/frei0r-1/rgbparade.so:${PORTSDIR}/graphics/frei0r-plugins-gavl
.endif

.if !defined(WITHOUT_OPENCV)
RUN_DEPENDS+=	${LOCALBASE}/lib/frei0r-1/facedetect.so:${PORTSDIR}/graphics/frei0r-plugins-opencv
.endif

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
