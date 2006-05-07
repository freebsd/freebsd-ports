# New ports collection makefile for:    gwget
# Date created:                		1 November 2004
# Whom:                    		Radek Kozlowski <radek@raadradd.com>
#
# $FreeBSD$
#

PORTNAME=	gwget
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	ftp www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	radek@raadradd.com
COMMENT=	A download manager for GNOME, based on wget

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gwget.schemas
EPHY_VER=	1.6

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/bin/epiphany) && !defined(WITHOUT_EPIPHANY)
WITH_EPIPHANY=	yes
.endif

.if defined(WITH_EPIPHANY)
BUILD_DEPENDS+=		epiphany:${PORTSDIR}/www/epiphany
CONFIGURE_ARGS+=	--enable-epiphany-extension \
			--with-epiphany-version=${EPHY_VER}
PLIST_SUB+=		EPIPHANY:="" \
			VERSION="${EPHY_VER}"
.else
CONFIGURE_ARGS+=	--disable-epiphany-extension
PLIST_SUB+=		EPIPHANY:="@comment "
.endif # defined(WITH_EPIPHANY)

post-patch:
	@${REINPLACE_CMD} -e 's|epiphany/extensions|epiphany-${EPHY_VER}/extensions|' \
		${WRKSRC}/epiphany-extension/Makefile.in

.include <bsd.port.post.mk>
