# New ports collection makefile for:	tilp
# Date created:		27 August 2003
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	tilp
PORTVERSION=	6.79
CATEGORIES=	comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI Linking Program

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	ticalcs.9:${PORTSDIR}/devel/libticalcs \
		ticables.12:${PORTSDIR}/comms/libticables \
		tifiles.6:${PORTSDIR}/devel/libtifiles

USE_GETTEXT=	yes
USE_GNOME=	gtk20 libglade2
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	15
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib -export-dynamic"

MAN1=	tilp.1

.include <bsd.port.pre.mk>

post-install:
	${MKDIR} ${PREFIX}/lib/tilp

.include <bsd.port.post.mk>
