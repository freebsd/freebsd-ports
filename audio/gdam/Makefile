# New ports collection makefile for:	gdam
# Date created:				6th Nov 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	gdam
PORTVERSION=	0.942
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	DJ mixing software suitable for live performances

BUILD_DEPENDS=	${LOCALBASE}/include/xmms/plugin.h:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

MAN1=		gdamcli.1 gdamladspapluginscanner.1 gdam123.1 gdam-launcher.1 gdam-server.1

USE_GMAKE=	yes
USE_GNOME=	libglade
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|`$$XMMS_CONFIG --libs`|"`$$XMMS_CONFIG --libs` ${PTHREAD_LIBS}"|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lglib -lgtk|-lglib-12 -lgtk-12|' ${WRKSRC}/skin/foreign/xmmsvis/Makefile.in
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
