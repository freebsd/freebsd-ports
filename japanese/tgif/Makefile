# New ports collection makefile for:	tgif-j
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tgif
PORTVERSION=	4.1.42
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://home.jp.FreeBSD.org/~mita/LOCAL_PORTS/
DISTNAME=	ja-${PORTNAME}-980222

MAINTAINER=	mita@FreeBSD.org
COMMENT=	2-D drawing facility (with Japanese configuration)

RUN_DEPENDS=	tgif:${PORTSDIR}/graphics/tgif-nls\
		${PREFIX}/lib/X11/fonts/local/knm12p.pcf.gz:${PORTSDIR}/japanese/k12

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults
	${INSTALL_DATA} ${WRKSRC}/Tgif ${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults/

.include <bsd.port.mk>
