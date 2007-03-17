# New ports collection makefile for:	mono-tools
# Date created:			2005-06-16
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.21 2007/02/07 15:46:06 killfill Exp $
#

PORTNAME=	mono-tools
PORTVERSION=	1.2.3
CATEGORIES=	devel
MASTER_SITES=	http://www.go-mono.com/sources/${PORTNAME}/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Documentation browser for Mono and Mono libraries

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20 \
		monodocer:${PORTSDIR}/devel/monodoc
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20 \
		monodocer:${PORTSDIR}/devel/monodoc

USE_GNOME=	gnomehack gnometarget gnomesharp20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	create-native-map.1

post-extract:
	@${REINPLACE_CMD} -e 's|@bindir@/monodoc|monodoc|g' \
		${WRKSRC}/docbrowser/monodoc.desktop.in
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/create-native-map/lib/pkgconfig/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
