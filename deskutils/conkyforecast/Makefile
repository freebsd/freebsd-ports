# New ports collection makefile for:	conkyforecast
# Date created:		2010-05-07
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	conkyforecast
PORTVERSION=	2.20
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpadlibrarian.net/70673352/ \
		http://fbsd.zlonet.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Weather forecast script for conky

LICENSE=	GPLv3

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	conky:${PORTSDIR}/sysutils/conky \
		pidof:${PORTSDIR}/sysutils/pidof \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALL_EGGINFO=yes
USES=		gettext
SUB_FILES=	pkg-message
SUB_LIST+=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}

WRKSRC=		${WRKDIR}/src

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/usr/share/${PORTNAME},${DATADIR},g' \
		setup.py \
		test/conkyForecast.test.conkyrc \
		test/conkyForecast.test.sh \
		example/conkyForecast.fontbased.sh \
		example/conkyForecast.fontbasedtemplate.conkyrc \
		example/conkyForecast.fontbasedtemplate.sh \
		example/conkyForecast.imagebasedtemplate.conkyrc \
		example/conkyForecast.imagebasedtemplate.sh \
		conkyForecast.py \
		conkyForecast \
		conkyForecast-SunsetSunriseCountdown
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/usr/bin/python,/usr/bin/env,g' \
		conkyForecast \
		conkyForecast-SunsetSunriseCountdown
	@cd ${WRKSRC} && ${RM} -fr test/*.bak example/*.bak

post-install:
	@${MKDIR} ${FONTSDIR}
	@${INSTALL_DATA} ${WRKSRC}/fonts/* ${FONTSDIR}
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${ECHO_MSG}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
