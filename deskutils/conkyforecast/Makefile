# New ports collection makefile for:	conkyforecast
# Date created:		2010-05-07
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	conkyforecast
PORTVERSION=	2.09
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/37518633/ \
		http://fbsd.zlonet.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Weather forecast script for conky

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	conky:${PORTSDIR}/sysutils/conky \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALL_EGGINFO=yes
USE_GETTEXT=	yes
SUB_FILES=	pkg-message
SUB_LIST+=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}

WRKSRC=		${WRKDIR}/src

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/usr/share/${PORTNAME},${DATADIR},g' \
		setup.py test/conkyrc example/conkyrc conkyForecast.py conkyForecast
	@cd ${WRKSRC} && ${RM} -fr test/conkyrc.bak example/conkyrc.bak

post-install:
	@${MKDIR} ${FONTSDIR}
	@${INSTALL_DATA} ${WRKSRC}/fonts/* ${FONTSDIR}
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${ECHO_MSG}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
