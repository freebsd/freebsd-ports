# New ports collection makefile for:   ptex-pkfonts
# Date created:        24 Dec 1999
# Whom:                Kentaro Inagaki <inagaki@tg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	ptex-pkfonts
PORTVERSION=	1.0
PORTREVISION=	1
PKGNAMESUFFIX=	${RESOLUTION}
CATEGORIES=	japanese print
DISTFILES=	# none

MAINTAINER=	inagaki@tg.rim.or.jp

RUN_DEPENDS=	${LOCALBASE}/lib/fonts/pk${RESOLUTION}:${PORTSDIR}/print/pkfonts${RESOLUTION}

NO_BUILD=	yes

# ******************
# USEPK_MODE:
#  Mode name of Metafont to give to print/pkfonts* is set.
#  It is care-and-attention to the other program how MetaFont wants to
#  be executed that do not use modeless. Kpathsea always searches
#  modeless because even if you specify any kind of mode.
# MAKETEX_MODE:
#  It is mode name of default at executing MetaFont. The default is ljfour.
#  This needs not to be changed. It can be changed with an option or resource.
# ******************
USEPK_MODE?=	cx
MAKETEX_MODE?=	${USEPK_MODE}
RESOLUTION?=	300

PLIST_SUB=	RESOLUTION="${RESOLUTION}" USEPK_MODE="${USEPK_MODE}"

.BEGIN:
.if defined(RESOLUTION) && \
	${RESOLUTION} != 118 && ${RESOLUTION} != 240 && \
	${RESOLUTION} != 300 && ${RESOLUTION} != 360 && \
	${RESOLUTION} != 400  && ${RESOLUTION} != 600
	@${ECHO_MSG} "Error: invalid value for RESOLUTION: \"${RESOLUTION}\""
	@${ECHO_MSG} "Possible values are: 118, 240, 300, 360, 400 and 600."
	@${FALSE}
.endif

do-install:
	${MKDIR} ${PREFIX}/share/texmf/fonts/pk/${USEPK_MODE}
	${LN} -sf ${PREFIX}/lib/fonts/pk${RESOLUTION} \
		${PREFIX}/share/texmf/fonts/pk/${USEPK_MODE}/

.include <bsd.port.mk>
