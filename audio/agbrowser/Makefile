# New ports collection makefile for:	agbrowser
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	agbrowser
PORTVERSION=	0.96
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/uallloveme/OSS/AGBrowser/

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	AGSatellite:${PORTSDIR}/audio/agsatellite

USE_KDELIBS_VER=2
GNU_CONFIGURE=	yes

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" -e "s|%%LOCALBASE%%|${LOCALBASE}|" \
		 ${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

pre-configure:
	@${TOUCH} `${FIND} -E ${WRKSRC} -regex ".*(Makefile|configure)\.(am|in)"`

post-install:
	@${MV} ${PREFIX}/bin/agbrowser ${PREFIX}/bin/agbrowser-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/agbrowser

.include <bsd.port.mk>
