# New ports collection makefile for:	tgif-j
# Version required:	4.0.17
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	ja-tgif-980222
PKGNAME=	ja-tgif-4.1.16
CATEGORIES=	japanese
MASTER_SITES=	http://home.jp.FreeBSD.org/~mita/LOCAL_PORTS/

MAINTAINER=	mita@jp.FreeBSD.org

RUN_DEPENDS=	tgif:${PORTSDIR}/graphics/tgif

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
USE_X_PREFIX=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/Tgif ${PREFIX}/lib/X11/app-defaults/

.include <bsd.port.mk>
