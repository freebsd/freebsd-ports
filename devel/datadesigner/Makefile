# ex:ts=8
# Ports collection makefile for:	datadesigner
# Date created:			Jul 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	datadesigner
PORTVERSION=	0.5
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dbdesign

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Database Schema Designer

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GNOME=	libxml2 libxslt
USE_ICONV=	yes
USE_WX=		2.4
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
