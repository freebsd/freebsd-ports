# New ports collection makefile for:	kimagemapeditor
# Date created:				19 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	kimagemapeditor
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	http://www.brueffer.de/distfiles/

MAINTAINER=	brueffer@phoenix-systems.de
COMMENT=	KDE-based editor for HTML image maps

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

pre-configure:
	${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
