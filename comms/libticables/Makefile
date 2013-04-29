# Created by: Tijl Coosemans <tijl@ulyssis.org>
# $FreeBSD$
#

PORTNAME=	libticables
PORTVERSION=	3.9.7
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=		SF/tilp/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TI calculator link cables library

DEPRECATED=     Superseded by comms/libticables2
EXPIRATION_DATE=2013-07-01

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gettext
USE_GNOME=	gnomehack pkgconfig
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes

EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure

.include <bsd.port.mk>
