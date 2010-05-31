# New ports collection makefile for:	zh-ibus-chewing
# Date created:				24 December 2009
# Whom:					Eric L. Chen <lihong@ieee.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-chewing
PORTVERSION=	1.2.0.20090817
PORTREVISION=	3
CATEGORIES=	chinese
MASTER_SITES=	http://github.com/definite/ibus-chewing/tarball/${PORTVERSION}/
DISTNAME=	definite-ibus-chewing-${GITCOMMIT}

MAINTAINER=	lihong@ieee.org
COMMENT=	Chewing engine for IBus

BUILD_DEPENDS=	gob2:${PORTSDIR}/devel/gob2 \
		ibus-daemon:${PORTSDIR}/textproc/ibus
RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus
LIB_DEPENDS=	chewing.3:${PORTSDIR}/chinese/libchewing

FETCH_BEFORE_ARGS=	-o ${DISTNAME}${EXTRACT_SUFX}
FETCH_ARGS=	-apRr

USE_GETTEXT=	yes
USE_GNOME=	gconf2 gtk20
USE_XORG=	xtst
GCONF_SCHEMAS=	ibus-chewing.schemas

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=yes
CMAKE_ARGS+=	-DSYSCONF_INSTALL_DIR=${PREFIX}/etc
GITCOMMIT=	8dd0478

.include <bsd.port.mk>
