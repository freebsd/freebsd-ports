# New ports collection makefile for:	gdam
# Date created:				6th Nov 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	gdam
PORTVERSION=	0.942
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	DJ mixing software suitable for live performances

BUILD_DEPENDS=	${X11BASE}/include/xmms/plugin.h:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

MAN1=		gdamcli.1 gdamladspapluginscanner.1 gdam123.1 gdam-launcher.1 gdam-server.1

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	libglade
USE_INC_LIBTOOL_VER=	13
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lglib -lgtk|-lglib12 -lgtk12|' ${WRKSRC}/skin/foreign/xmmsvis/Makefile.in

.include <bsd.port.mk>
