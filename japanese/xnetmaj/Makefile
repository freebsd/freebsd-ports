# New ports collection makefile for:   xnetmaj
# Version required:    2.0.7
# Date created:        20 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.3 1998/11/29 12:43:13 asami Exp $
#

DISTNAME=	netmaj
PKGNAME=	ja-xnetmaj-2.0.7
CATEGORIES=	japanese games
MASTER_SITES=	http://www.sfc.wide.ad.jp/~kusune/netmaj/files/
DISTFILES=	netmaj-2.0.7.tar.gz netmaj-xui-2.0.7.tar.gz

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
ALL_TARGET=	libs all
INSTALL_TARGET=	install install-pf

post-extract:
	( cd ${WRKDIR}/netmaj; /bin/ln -s ../xui )

.include <bsd.port.mk>
