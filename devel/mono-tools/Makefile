# New ports collection makefile for:	mono-tools
# Date created:			2005-06-16
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $Id: Makefile,v 1.3 2005/07/02 22:27:12 apeiron Exp $
# $FreeBSD$
#

PORTNAME=	mono-tools
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.go-mono.com/sources/${PORTNAME}/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Documentation browser for Mono and Mono libraries

BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp \
		monodocer:${PORTSDIR}/devel/monodoc
RUN_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp \
		monodocer:${PORTSDIR}/devel/monodoc

USE_GNOME=	gnomehack gnometarget
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|@bindir@/monodoc|monodoc|g' \
		${WRKSRC}/docbrowser/monodoc.desktop.in

.include <bsd.port.mk>
