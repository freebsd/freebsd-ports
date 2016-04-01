# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	musictracker
PORTVERSION=	0.4.1
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	pidgin-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin for Pidgin to displays the music track currently playing

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/pidgin/pidgin.h:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin
LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		gmake libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-return-type
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/pidgin/musictracker.so

.include <bsd.port.mk>
