# New ports collection makefile for:	gnomemedia2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomemedia2
PORTVERSION=	2.6.2
PORTREVISION=	6
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-media/2.6
DISTNAME=	gnome-media-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the GNOME 2 desktop

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack gnomehier gnomedesktop \
		gail gstreamerplugins
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]CDROM_HOST[)]|freebsd|g' \
		${WRKSRC}/gnome-cd/Makefile.in
.if ${OSVERSION} > 501107
	@${REINPLACE_CMD} -e 's|%%CDROM%%|acd0|' ${WRKSRC}/configure
.else
	@${REINPLACE_CMD} -e 's|%%CDROM%%|acd0c|' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
