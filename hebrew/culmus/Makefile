# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	culmus
PORTVERSION=	0.130
PORTREVISION=	1
CATEGORIES=	hebrew
MASTER_SITES=	SF

MAINTAINER=	onatan@gmail.com
COMMENT=	Free Hebrew Type1 fonts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=	fonts
NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for filename in AharoniCLM-Bold AharoniCLM-BoldOblique AharoniCLM-Book AharoniCLM-BookOblique CaladingsCLM DrugulinCLM-Bold DrugulinCLM-BoldItalic ElliniaCLM-Bold ElliniaCLM-BoldItalic ElliniaCLM-Light ElliniaCLM-LightItalic NachlieliCLM-Bold NachlieliCLM-BoldOblique NachlieliCLM-Light NachlieliCLM-LightOblique YehudaCLM-Bold YehudaCLM-Light
		${INSTALL_DATA} ${WRKSRC}/${filename}.afm ${STAGEDIR}${FONTSDIR}
		${INSTALL_DATA} ${WRKSRC}/${filename}.pfa ${STAGEDIR}${FONTSDIR}
.endfor
.for filename in DavidCLM-Bold DavidCLM-BoldItalic DavidCLM-Medium DavidCLM-MediumItalic FrankRuehlCLM-Bold FrankRuehlCLM-BoldOblique FrankRuehlCLM-Medium FrankRuehlCLM-MediumOblique HadasimCLM-Bold HadasimCLM-BoldOblique HadasimCLM-Regular HadasimCLM-RegularOblique KeterYG-Bold KeterYG-BoldOblique KeterYG-Medium KeterYG-MediumOblique MiriamCLM-Bold MiriamCLM-Book MiriamMonoCLM-Bold MiriamMonoCLM-BoldOblique MiriamMonoCLM-Book MiriamMonoCLM-BookOblique ShofarDemi-Bold ShofarDemi-BoldOblique ShofarRegular ShofarRegularOblique SimpleCLM-Bold SimpleCLM-BoldOblique SimpleCLM-Medium SimpleCLM-MediumOblique StamAshkenazCLM StamSefaradCLM
		${INSTALL_DATA} ${WRKSRC}/${filename}.ttf ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
