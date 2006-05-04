# New ports collection makefile for:	mono-tools
# Date created:			2005-06-16
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.13 2006/01/03 03:35:56 tmclau02 Exp $
#

PORTNAME=	mono-tools
PORTVERSION=	1.1.11
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.go-mono.com/sources/${PORTNAME}/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Documentation browser for Mono and Mono libraries

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gecko-sharp.pc:${PORTSDIR}/www/gecko-sharp10 \
		monodocer:${PORTSDIR}/devel/monodoc
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gecko-sharp.pc:${PORTSDIR}/www/gecko-sharp10 \
		monodocer:${PORTSDIR}/devel/monodoc

USE_GNOME=	gnomehack gnometarget
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|@bindir@/monodoc|monodoc|g' \
		${WRKSRC}/docbrowser/monodoc.desktop.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
