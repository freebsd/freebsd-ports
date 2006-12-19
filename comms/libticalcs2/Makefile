# New ports collection makefile for:	libticalcs2
# Date created:		11 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticalcs2
PORTVERSION=	1.0.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtktiemu
DISTNAME=	${PORTNAME}-20061030

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator library

LIB_DEPENDS=	ticables2.1:${PORTSDIR}/comms/libticables2 \
		ticonv.2:${PORTSDIR}/converters/libticonv \
		tifiles2.3:${PORTSDIR}/devel/libtifiles2

WRKSRC=		${WRKDIR}/libticalcs

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GCC=	3.4+
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack pkgconfig
USE_LDCONFIG=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
