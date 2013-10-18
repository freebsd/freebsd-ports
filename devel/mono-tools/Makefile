# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	mono-tools
PORTVERSION=	2.10
CATEGORIES=	devel
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Documentation browser for Mono and Mono libraries

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

LIB_DEPENDS=	gdiplus.0:${PORTSDIR}/x11-toolkits/libgdiplus
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/webkit-sharp-1.0.pc:${PORTSDIR}/www/webkit-sharp
RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN=		does not build

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomedesktopsharp20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		create-native-map.1 gd2i.1 gendarme.1 mperfmon.1 \
		mprof-decoder.1 mprof-heap-viewer.1
MAN5=		gendarme.5

NO_STAGE=	yes
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
