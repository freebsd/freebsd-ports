# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	conkyforecast
PORTVERSION=	2.20
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpadlibrarian.net/70673352/ \
		LOCAL/vg
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
INSTALLS_EGGINFO=	yes
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
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	@${INSTALL_DATA} ${WRKSRC}/fonts/* ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
