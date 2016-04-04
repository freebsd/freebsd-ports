# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PKGNAMEPREFIX=	xmms-

COMMENT=	XMMS plugin for playing .nsf and .hes audio files

MASTERDIR=	${.CURDIR}/../festalon

BUILD_DEPENDS=	xmms:multimedia/xmms
RUN_DEPENDS=	xmms:multimedia/xmms

USE_GNOME=	glib12
CONFIGURE_ARGS+=	--enable-interface=interface
INSTALL_TARGET=	install-strip

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PLIST_FILES=	lib/xmms/Input/libfestalon_xmms.a \
		lib/xmms/Input/libfestalon_xmms.so \
		lib/xmms/Input/libfestalon_xmms.so.0 \
		lib/xmms/Input/libfestalon_xmms.so.0.0.0


.include "${MASTERDIR}/Makefile"
