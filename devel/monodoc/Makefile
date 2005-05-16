# New ports collection makefile for:    MonoDoc
# Date created:         2004-08-13
# Friday the 13th!
# Whom:                 Christopher Nehren
#
# $Id: Makefile,v 1.17 2005/05/16 02:37:15 mezz7 Exp $
# $FreeBSD$
#

PORTNAME=	monodoc
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.go-mono.com/archive/${PORTVERSION}/

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Documentation browser for Mono and Mono libraries

BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp \
		${LOCALBASE}/bin/lynx:${PORTSDIR}/www/lynx
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gnomehack gnometarget
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

USE_REINPLACE=	yes

# Fix 'exec mono' not picking up libmap.conf settings.
post-patch:
	@${REINPLACE_CMD} -e 's|mono |${LOCALBASE}/bin/mono |g' \
		${WRKSRC}/monodoc.in

.include <bsd.port.mk>
