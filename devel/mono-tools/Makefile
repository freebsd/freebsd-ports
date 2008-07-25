# New ports collection makefile for:	mono-tools
# Date created:			2005-06-16
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.26 2007/05/21 02:18:46 killfill Exp $
#

PORTNAME=	mono-tools
PORTVERSION=	1.2.4
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	bsd-sharp@googlegroups.com
COMMENT=	Documentation browser for Mono and Mono libraries

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20 \
		monodocer:${PORTSDIR}/devel/monodoc
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20 \
		monodocer:${PORTSDIR}/devel/monodoc

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget gnomesharp20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GECKO=	firefox mozilla
CONFIGURE_ARGS=	--mandir=${PREFIX}/man

MAN1=	create-native-map.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|@bindir@/monodoc|monodoc|g' \
		${WRKSRC}/docbrowser/monodoc.desktop.in
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/create-native-map/lib/pkgconfig/Makefile.in
	@${REINPLACE_CMD} -e "s|%%FBSD_MOZILLA_HOME%%|${PREFIX}/lib/${GECKO}|g" \
		${WRKSRC}/docbrowser/monodoc.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
