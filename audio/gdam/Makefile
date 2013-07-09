# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	gdam
PORTVERSION=	0.942
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DJ mixing software suitable for live performances

DEPRECATED=	Broken for a while
EXPIRATION_DATE=	2013-07-10

BUILD_DEPENDS=	${LOCALBASE}/include/xmms/plugin.h:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

MAN1=		gdamcli.1 gdamladspapluginscanner.1 gdam123.1 gdam-launcher.1 gdam-server.1

USE_GMAKE=	yes
USE_GNOME=	libglade
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|`$$XMMS_CONFIG --libs`|"`$$XMMS_CONFIG --libs` ${PTHREAD_LIBS}"|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lglib -lgtk|-lglib-12 -lgtk-12|' ${WRKSRC}/skin/foreign/xmmsvis/Makefile.in
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 900000 && ${OSVERSION} >= 802502) || ${OSVERSION} >= 900027
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
