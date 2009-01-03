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

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A combine of Kai and Sung with CNS11643 TrueType Fonts

DIST_SUBDIR=	${PORTNAME}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

TTF=		TW-Kai-95_1_3.ttf TW-Sung-95_1_3.ttf

do-install:
	@${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/TW-Kai-95_1_3.ttf ${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/TW-Sung-95_1_3.ttf ${FONTSDIR}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
