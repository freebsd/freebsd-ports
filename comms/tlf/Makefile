PORTNAME=	tlf
PORTVERSION=	1.4.1
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	4
CATEGORIES=	comms hamradio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	851321c0979c.patch:-p1 # https://github.com/Tlf/tlf/pull/268
PATCHFILES+=	3c48ad1c95c8.patch:-p1 # https://github.com/Tlf/tlf/pull/268
PATCHFILES+=	4302ec05ed9f.patch:-p1 # https://github.com/Tlf/tlf/pull/268

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio curses based logging program
WWW=		https://github.com/Tlf/tlf

LICENSE=	GPLv2

LIB_DEPENDS=	libargp.so:devel/argp-standalone
RUN_DEPENDS=	rec:audio/sox \
		wget:ftp/wget

USES=		autoreconf gnome ncurses pkgconfig
USE_GITHUB=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -largp" \
		CPPFLAGS=-I${LOCALBASE}/include

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	HAMLIB FLDIGI DOCS
HAMLIB_DESC=	Support rig control via hamlib
FLDIGI_DESC=	Support fldigi XML-RPC integration
OPTIONS_DEFAULT=HAMLIB FLDIGI

HAMLIB_LIB_DEPENDS=	libhamlib.so:comms/hamlib
HAMLIB_CONFIGURE_ENABLE=hamlib
FLDIGI_LIB_DEPENDS=	libxmlrpc.so:net/xmlrpc-c
FLDIGI_CONFIGURE_ENABLE=fldigi-xmlrpc

.include <bsd.port.mk>
