# New ports collection makefile for:	kompose
# Date created:				31 Aug 2004
# Whom:					Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	kompose
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	http://download.berlios.de/kompose/

MAINTAINER=	lauri@kde.org
COMMENT=	Full-screen task manager similar to Exposé(tm)

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_KDELIBS_VER=	3
GNU_CONFIGURE=	yes

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
