# New ports collection makefile for:	libticalcs2
# Date created:		11 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticalcs2
PORTVERSION=	1.1.2
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.11
DISTNAME=	tilibs2-20080328

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator library

LIB_DEPENDS=	ticables2.1:${PORTSDIR}/comms/libticables2 \
		ticonv.3:${PORTSDIR}/converters/libticonv \
		tifiles2.5:${PORTSDIR}/devel/libtifiles2

USE_AUTOTOOLS=	libtool:22
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

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-extract:
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/tilibs2/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}

.include <bsd.port.mk>
