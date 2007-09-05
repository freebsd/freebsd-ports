# New ports collection makefile for:	libticalcs2
# Date created:		11 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticalcs2
PORTVERSION=	1.0.7
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp
DISTFILES=	tilibs2-20070829${EXTRACT_SUFX}

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator library

LIB_DEPENDS=	ticables2.1:${PORTSDIR}/comms/libticables2 \
		ticonv.3:${PORTSDIR}/converters/libticonv \
		tifiles2.4:${PORTSDIR}/devel/libtifiles2

USE_AUTOTOOLS=	libtool:15
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

.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/tilibs2/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}

.include <bsd.port.post.mk>
