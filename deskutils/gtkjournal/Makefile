# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkjournal
PORTVERSION=	0.3.5.b
PORTREVISION=	13
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://sourcefiles.org/Productivity_Tools/Diary/ \
		LOCAL/beech
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+-2 journal/diary

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtkmm20 \
		sqlite.2:${PORTSDIR}/databases/sqlite2 \
		gtkspell:${PORTSDIR}/textproc/gtkspell

PLIST_FILES=	bin/gtkjournal lib/libsqlitemm.a lib/libsqlitemm.la \
		lib/libsqlitemm.so lib/libsqlitemm.so.0

USE_AUTOTOOLS=	libtool
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	lthack
CONFIGURE_ARGS=	--enable-gtkspell
USE_LDCONFIG=	yes

MAN1=		${PORTNAME}.1

NO_STAGE=	yes
.include <bsd.port.mk>
