# New ports collection makefile for:   xnetmaj
# Date created:        20 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xnetmaj
PORTVERSION=	2.0.7
CATEGORIES=	japanese games
MASTER_SITES=	http://www.sfc.wide.ad.jp/~kusune/netmaj/files/
DISTNAME=	netmaj
DISTFILES=	netmaj-${PORTVERSION}.tar.gz \
		netmaj-xui-${PORTVERSION}.tar.gz

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	libs all
INSTALL_TARGET=	install install-pf

post-extract:
	( cd ${WRKDIR}/netmaj; ${LN} -s ../xui )

.include <bsd.port.mk>
