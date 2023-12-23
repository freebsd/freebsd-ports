PORTNAME=	xnec2c
PORTVERSION=	4.4.12
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	https://www.xnec2c.org/releases/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Used to calculate antenna patterns useful to ham radio
WWW=		https://www.qsl.net/5b4az/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf desktop-file-utils gettext gmake gnome pkgconfig shared-mime-info

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS=-lexecinfo
CONFIGURE_ENV+=	LDFLAGS="-L/${LOCALBASE}/lib ${LDFLAGS}"

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool

.include <bsd.port.mk>
