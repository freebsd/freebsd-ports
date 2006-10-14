# New ports collection makefile for:	gwget
# Date created:				1 November 2004
# Whom:					Radek Kozlowski <radek@raadradd.com>
#
# $FreeBSD$
#

PORTNAME=	gwget
PORTVERSION=	0.98.1
PORTREVISION=	1
CATEGORIES=	ftp www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	radek@raadradd.com
COMMENT=	A download manager for GNOME, based on wget

BROKEN=		fails to install
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2006-12-01

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui libbonobo gconf2
GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBBONOBO_IDL="-I${LOCALBASE}/idl/bonobo-2.0" \
		LDFLAGS="-Wl,-export-dynamic -L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gwget.schemas
EPHY_VER?=	2.14

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/epiphany) && !defined(WITHOUT_EPIPHANY)
WITH_EPIPHANY=	yes
.endif

.if defined(WITH_EPIPHANY)
BUILD_DEPENDS+=		epiphany:${PORTSDIR}/www/epiphany
CONFIGURE_ARGS+=	--enable-epiphany-extension \
			--with-epiphany-version=${EPHY_VER}
PLIST_SUB+=		EPIPHANY="" \
			VERSION="${EPHY_VER}"
.else
CONFIGURE_ARGS+=	--disable-epiphany-extension
PLIST_SUB+=		EPIPHANY="@comment "
.endif # defined(WITH_EPIPHANY)

post-patch:
	@${REINPLACE_CMD} -e 's|epiphany/extensions|epiphany-${EPHY_VER}/extensions|' \
		${WRKSRC}/epiphany-extension/Makefile.in

.include <bsd.port.post.mk>
