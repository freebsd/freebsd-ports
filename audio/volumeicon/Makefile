# $FreeBSD$

PORTNAME=	volumeicon
PORTVERSION=	0.5.0
CATEGORIES=	audio
MASTER_SITES=	http://softwarebakery.com/maato/files/volumeicon/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Lightweight volume control for the systray

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-oss \
		--with-oss-include-path=/usr/include/sys
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USES=		gmake gettext pkgconfig
USE_GNOME=	gtk30 intltool

OPTIONS_DEFINE=		NLS NOTIFY
OPTIONS_DEFAULT=	NOTIFY
OPTIONS_SUB=		yes

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=notify

.include <bsd.port.mk>
