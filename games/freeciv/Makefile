# New ports collection makefile for:	freeciv
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

PORTNAME=	freeciv
PORTVERSION=	2.0.9
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Free turn-based multiplayer strategy

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-libiconv-prefix=${PREFIX} --program-transform-name=

MAN6=		civserver.6 civclient.6

.ifndef WITHOUT_X11
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png
USE_XPM=	yes
USE_SDL=	mixer
PLIST_SUB=	X11=""
USE_GNOME=	gtk20
CONFIGURE_ARGS+=--enable-client=gtk2
.ifndef WITHOUT_ESOUND
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=--disable-esd
.endif
.else
PLIST_SUB=	X11="@comment "
PKGNAMESUFFIX?=	-nox11
CONFIGURE_ARGS+=--enable-client=no
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test.*==/s|==|=|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in|${XARGS} ${REINPLACE_CMD} -e\
		'/pkgdatadir/s|$$[(]datadir[)]/@PACKAGE@|${DATADIR}|'

.include <bsd.port.mk>
