# New ports collection makefile for:	freeciv
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

PORTNAME=	freeciv
PORTVERSION=	2.1.3
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Free turn-based multiplayer strategy

RUN_DEPENDS=	hicolor-icon-theme>=0:${PORTSDIR}/misc/hicolor-icon-theme

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-libiconv-prefix=${PREFIX} --program-transform-name=
INSTALLS_ICONS=	yes
PORT_VERBS=	civ

MAN6=		civserver.6 civclient.6

.ifndef WITHOUT_X11
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		ggz.5:${PORTSDIR}/games/libggz \
		ggz-gtk.1:${PORTSDIR}/games/ggz-gtk-client \
		ggzcore.9:${PORTSDIR}/games/ggz-client-libs \
		ggzmod.5:${PORTSDIR}/games/ggz-client-libs
USE_XPM=	yes
USE_SDL=	mixer
USE_GNOME=	gtk20
CONFIGURE_ARGS+=--enable-client=gtk
.ifndef WITHOUT_ESOUND
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=--disable-esd
.endif
CONFLICTS=	freeciv-nox11-[0-9]*
.else
PLIST=	${PKGDIR}/pkg-plist.nox11
PKGNAMESUFFIX?=	-nox11
CONFIGURE_ARGS+=--enable-client=no
CONFLICTS=	freeciv-[0-9]*
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test.*==/s|==|=|;\
		/^LIBS/s|mixer|mixer $$SDL_LIBS|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in|${XARGS} ${REINPLACE_CMD} -e\
		'/pkgdatadir/s|$$[(]datadir[)]/@PACKAGE@|${DATADIR}|'

.ifndef WITHOUT_X11
post-install:
	@${INSTALL_DATA} ${WRKSRC}/data/civclient.dsc ${DATADIR}/
.endif

.include <bsd.port.mk>
