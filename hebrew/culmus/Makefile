# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	culmus
PORTVERSION=	0.130
CATEGORIES=	hebrew
MASTER_SITES=	SF

MAINTAINER=	onatan@gmail.com
COMMENT=	Free Hebrew Type1 fonts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/fonts/culmus
.for filename in AharoniCLM-Bold AharoniCLM-BoldOblique AharoniCLM-Book AharoniCLM-BookOblique CaladingsCLM DrugulinCLM-Bold DrugulinCLM-BoldItalic ElliniaCLM-Bold ElliniaCLM-BoldItalic ElliniaCLM-Light ElliniaCLM-LightItalic NachlieliCLM-Bold NachlieliCLM-BoldOblique NachlieliCLM-Light NachlieliCLM-LightOblique YehudaCLM-Bold YehudaCLM-Light
		${INSTALL_DATA} ${WRKSRC}/${filename}.afm ${STAGEDIR}${PREFIX}/lib/X11/fonts/culmus
		${INSTALL_DATA} ${WRKSRC}/${filename}.pfa ${STAGEDIR}${PREFIX}/lib/X11/fonts/culmus
.endfor
.for filename in DavidCLM-Bold DavidCLM-BoldItalic DavidCLM-Medium DavidCLM-MediumItalic FrankRuehlCLM-Bold FrankRuehlCLM-BoldOblique FrankRuehlCLM-Medium FrankRuehlCLM-MediumOblique HadasimCLM-Bold HadasimCLM-BoldOblique HadasimCLM-Regular HadasimCLM-RegularOblique KeterYG-Bold KeterYG-BoldOblique KeterYG-Medium KeterYG-MediumOblique MiriamCLM-Bold MiriamCLM-Book MiriamMonoCLM-Bold MiriamMonoCLM-BoldOblique MiriamMonoCLM-Book MiriamMonoCLM-BookOblique ShofarDemi-Bold ShofarDemi-BoldOblique ShofarRegular ShofarRegularOblique SimpleCLM-Bold SimpleCLM-BoldOblique SimpleCLM-Medium SimpleCLM-MediumOblique StamAshkenazCLM StamSefaradCLM
		${INSTALL_DATA} ${WRKSRC}/${filename}.ttf ${STAGEDIR}${PREFIX}/lib/X11/fonts/culmus
.endfor

	@cd ${WRKSRC}; ${PREFIX}/bin/mkfontscale; ${PREFIX}/bin/mkfontdir
	${INSTALL_DATA} ${WRKSRC}/fonts.scale-* ${STAGEDIR}${PREFIX}/lib/X11/fonts/culmus

.include <bsd.port.mk>
