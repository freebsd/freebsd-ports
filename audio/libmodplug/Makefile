# New ports collection makefile for:   libmodplug
# Date created:		3 February 2004
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	libmodplug
PORTVERSION=	0.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	modplug-xmms

MAINTAINER=	ehaupt@critical.ch
COMMENT=	ModPlug mod-like music shared libraries

INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_INC_LIBTOOL_VER=	15
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
