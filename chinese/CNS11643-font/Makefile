# New ports collection makefile for:	CNS11643-font
# Date created:		2009/01/03
# Whom:			chinsan
#
# $FreeBSD$
#

PORTNAME=	CNS11643-font
PORTVERSION=	95.1.3
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	LOCAL/chinsan/fonts/ \
		http://www.cns11643.gov.tw/cns11643/images/ttf/
PKGNAMEPREFIX=	zh-
DISTFILES=	TW-Kai-95_1_3.ttf TW-Sung-95_1_3.ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A combine of Kai and Sung with CNS11643 TrueType Fonts

DIST_SUBDIR=	${PORTNAME}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
RESTRICTED=	"No redistribution or commercial use is allowed."

TTF=		TW-Kai-95_1_3.ttf TW-Sung-95_1_3.ttf

do-extract:
	@${MKDIR} ${WRKDIR}

do-install:
	@${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}/TW-Kai-95_1_3.ttf ${FONTSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}/TW-Sung-95_1_3.ttf ${FONTSDIR}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
