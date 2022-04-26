PORTNAME=	lux
PORTVERSION=	1.1.0a
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/kfj/pv/get/
PKGNAMESUFFIX=	-pv	# distinguish from www/lux
DISTNAME=	${COMMIT}

MAINTAINER=	fuz@fuz.su
COMMENT=	Panorama and image viewer

LICENSE=	GPLv3 SANSATION
LICENSE_COMB=	multi
LICENSE_NAME_SANSATION=	Sansation freeware font family license
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE
LICENSE_FILE_SANSATION=	${WRKSRC}/Sansation_1.31_ReadMe.txt
LICENSE_PERMS_SANSATION=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BUILD_DEPENDS=	vc>0:devel/vc
LIB_DEPENDS=	libvigraimpex.so:graphics/vigra \
		libsfml-window.so:devel/sfml \
		libexiv2.so:graphics/exiv2

USES=		cmake dos2unix pkgconfig tar:bz2
DOS2UNIX_FILES=	tinyfiledialogs.c
CONFLICTS=	lux
DESKTOP_ENTRIES=	"Lux Panorama Viewer" \
			"panorama and image viewer" "lux-pv" "lux" \
			"Graphics;ImageProcessing;Photography;Viewer;" \
			false

WRKSRC=		${WRKDIR}/kfj-pv-${COMMIT}
COMMIT=		b5011de5af40
PLIST_FILES=	bin/lux \
		share/icons/hicolor/512x512/apps/lux-pv.png \
		share/lux/fonts/Sansation_1.31_ReadMe.txt \
		share/lux/fonts/Sansation_Regular.ttf

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/scripts/PV_512x512x32.png \
	    ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/lux-pv.png

.include <bsd.port.mk>
