# Created by: Stefan Jahn <stefan.jahn@nemesis-sektor.de>
# $FreeBSD$

PORTNAME=	gqradio
PORTVERSION=	1.9.2
PORTREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	SF/gqmpeg/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 based FM tuner

LICENSE=	GPLv2

USES=		gettext gnome pathfix pkgconfig xorg
USE_GNOME=	gtk20
USE_XORG=	x11
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm -lX11

OPTIONS_DEFINE=		DOCS V4L

V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_CONFIGURE_ENV_OFF=	ac_cv_header_linux_videodev_h=no

post-patch:
	@${REINPLACE_CMD} -e \
		's|header_machine_ioctl_bt848|header_dev_bktr_ioctl_bt848| ; \
		 s|machine/ioctl_bt848|dev/bktr/ioctl_bt848| ; \
		 s|\(doc/gqradio\)-\$$VERSION|\1|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^\(readmedir = \).*|\1$$(prefix)/share/doc/gqradio|; \
		 s|COPYING||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|^\(Icon=\).*|\1${PREFIX}/share/pixmaps/gqradio.png|' \
		${WRKSRC}/gqradio.desktop
	@${REINPLACE_CMD} -e \
		's|machine/ioctl_bt848|dev/bktr/ioctl_bt848|' \
		${WRKSRC}/src/io_radio.c

.include <bsd.port.mk>
