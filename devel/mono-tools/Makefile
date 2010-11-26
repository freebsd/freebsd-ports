# New ports collection makefile for:	mono-tools
# Date created:			2005-06-16
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.30 2007/12/13 19:32:53 killfill Exp $
#

PORTNAME=	mono-tools
PORTVERSION=	2.6.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Documentation browser for Mono and Mono libraries

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20 \
		${LOCALBASE}/lib/libgdiplus.a:${PORTSDIR}/x11-toolkits/libgdiplus
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget gnomedesktopsharp20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GECKO=	libxul

MAN1=		create-native-map.1 gendarme.1 mprof-decoder.1 mprof-heap-viewer.1
MAN5=		gendarme.5

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|@bindir@/monodoc|monodoc|g' \
		${WRKSRC}/docbrowser/monodoc.desktop.in
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/create-native-map/lib/pkgconfig/Makefile.in
	@${REINPLACE_CMD} -e "s|%%FBSD_MOZILLA_HOME%%|${PREFIX}/lib/${GECKO}|g" \
		${WRKSRC}/docbrowser/monodoc.in
	@${FIND} ${WRKSRC} -name "${GNOME_MAKEFILEIN}*" -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|@datadir@/man/man1|@mandir@/man1|g'

.include "${PORTSDIR}/lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
