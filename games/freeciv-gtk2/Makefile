# New ports collection makefile for:	freeciv
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

PORTNAME=	freeciv
PORTVERSION=	1.14.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/pub/freeciv/stable/ \
		ftp://ftp.netc.pt/pub/freeciv/stable/ \
		ftp://ftp.pvv.ntnu.no/pub/freeciv/stable/

MAINTAINER?=	adam-ports@blacktabby.org
COMMENT?=	A civilisation clone for X11; multiplayer

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_XPM=	yes
USE_BZIP2=	yes
WANT_GNOME=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	imlib
PKGNAMESUFFIX?=	-imlib
.else
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

post-patch:
	cd ${WRKSRC}; ${FIND} . -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e 's/@program_transform_name@//'

.include <bsd.port.post.mk>
