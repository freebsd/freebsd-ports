# New ports collection makefile for:	tilp
# Date created:		27 August 2003
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	tilp
PORTVERSION=	6.68
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI Linking Program

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	ticalcs-4.5:${PORTSDIR}/devel/libticalcs \
		ticables.10:${PORTSDIR}/comms/libticables \
		tifiles.5:${PORTSDIR}/devel/libtifiles

USE_GETTEXT=	yes
USE_GNOME=	gtk20 libglade2
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	13
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	tilp.1

.include <bsd.port.pre.mk>

.if defined(WITH_JPEG) || exists(${LOCALBASE}/lib/libjpeg.so.9)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
.else
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG} "If you want to compile with JPEG support, hit Ctrl-C"
	@${ECHO_MSG} "right now and use \"make WITH_JPEG=yes\""
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG}
.endif #WITH_JPEG

post-install:
	${MKDIR} ${PREFIX}/lib/tilp

.include <bsd.port.post.mk>
