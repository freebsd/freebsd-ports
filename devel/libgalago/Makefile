# New ports collection makefile for:	libgalago
# Date created:				Apr 27 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgalago
PORTVERSION=	0.5.2
PORTREVISION=	3
CATEGORIES=	devel deskutils
MASTER_SITES=	http://www.galago-project.org/files/releases/source/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Galago desktop presence library

LIB_PC_DEPENDS=	dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib

BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}

USE_GNOME=	gnomehack pkgconfig
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

post-configure:
	@${ECHO_CMD} "#define HAVE_STRCHR 1" >> ${WRKSRC}/config.h

.include <bsd.port.mk>
