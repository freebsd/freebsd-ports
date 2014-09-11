# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkjournal
PORTVERSION=	0.3.5.b
PORTREVISION=	17
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://sourcefiles.org/Productivity_Tools/Diary/ \
		LOCAL/beech
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+-2 journal/diary

LIB_DEPENDS=	libgtkmm-2.0.so:${PORTSDIR}/x11-toolkits/gtkmm20 \
		libsqlite.so:${PORTSDIR}/databases/sqlite2 \
		libgtkspell.so:${PORTSDIR}/textproc/gtkspell

PLIST_FILES=	bin/gtkjournal man/man1/gtkjournal.1.gz \
		lib/libsqlitemm.a lib/libsqlitemm.so \
		lib/libsqlitemm.so.0 lib/libsqlitemm.so.0.0.1

USES=		gmake libtool pathfix pkgconfig
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gtkspell
USE_LDCONFIG=	yes

.include <bsd.port.mk>
