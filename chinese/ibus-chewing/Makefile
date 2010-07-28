# New ports collection makefile for:	zh-ibus-chewing
# Date created:				24 December 2009
# Whom:					Eric L. Chen <lihong@ieee.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-chewing
PORTVERSION=	1.3.5.20100706
CATEGORIES=	chinese
MASTER_SITES=	http://ibus.googlecode.com/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

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

.include <bsd.port.mk>
