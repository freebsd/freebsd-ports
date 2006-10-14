# New ports collection makefile for:	evolution-jescs
# Date created:				08 September 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/evolution-jescs/Makefile,v 1.14 2006/09/29 20:24:23 ahze Exp $
#

PORTNAME=	jescs
PORTVERSION=	2.8.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PKGNAMEPREFIX}${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	evolution-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sun Java Enterprise System Calendar Server provider for Evolution

BUILD_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

EVO_VERSION=	2.8
PLIST_SUB=	EVO_VERSION=${EVO_VERSION} EDS_VERSION="1.2" VERSION="2.8"

post-patch:
	@${REINPLACE_CMD} -e 's|libdir/bonobo/servers|prefix/libdata/bonobo/servers|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
