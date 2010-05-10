# New ports collection makefile for:	evolution-jescs
# Date created:				08 September 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/evolution-jescs/Makefile,v 1.40 2009/11/28 05:58:58 mezz Exp $
#

PORTNAME=	evolution-jescs
PORTVERSION=	2.28.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sun Java Enterprise System Calendar Server provider for Evolution

BUILD_DEPENDS=	evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	evolution:${PORTSDIR}/mail/evolution

IGNORE=		Doesn't build or work with Evolution 2.30

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_UNSAFE=	yes

EVO_VERSION=	2.28
PLIST_SUB=	EVO_VERSION=${EVO_VERSION} EDS_VERSION="1.2" VERSION="2.28"

post-patch:
	@${REINPLACE_CMD} -e 's|libdir/bonobo/servers|prefix/libdata/bonobo/servers|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
