# Ports collection makefile for:  culmus
# Date created:			  11 Apr 2003
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	culmus
PORTVERSION=	0.100
CATEGORIES=	hebrew
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	onatan@gmail.com
COMMENT=	Free Hebrew Type1 fonts

BUILD_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/X11/fonts/culmus
.	for filename in AharoniCLM-Bold AharoniCLM-BoldOblique AharoniCLM-Book AharoniCLM-BookOblique CaladingsCLM DavidCLM-Bold DavidCLM-Medium DavidCLM-MediumItalic DrugulinCLM-Bold DrugulinCLM-BoldItalic ElliniaCLM-Bold ElliniaCLM-BoldItalic ElliniaCLM-Light ElliniaCLM-LightItalic FrankRuehlCLM-Bold FrankRuehlCLM-BoldOblique FrankRuehlCLM-Medium FrankRuehlCLM-MediumOblique MiriamCLM-Bold MiriamCLM-Book MiriamMonoCLM-Bold MiriamMonoCLM-BoldOblique MiriamMonoCLM-Book MiriamMonoCLM-BookOblique NachlieliCLM-Bold NachlieliCLM-BoldOblique NachlieliCLM-Light NachlieliCLM-LightOblique YehudaCLM-Bold YehudaCLM-Light
		${INSTALL_DATA} ${WRKSRC}/${filename}.afm ${PREFIX}/lib/X11/fonts/culmus
		${INSTALL_DATA} ${WRKSRC}/${filename}.pfa ${PREFIX}/lib/X11/fonts/culmus
.	endfor
	@cd ${WRKSRC}; ${PREFIX}/bin/mkfontscale; ${PREFIX}/bin/mkfontdir
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/lib/X11/fonts/culmus
	${INSTALL_DATA} ${WRKSRC}/fonts.scale ${PREFIX}/lib/X11/fonts/culmus

post-install:
	@${SED} "s|PREFIX|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.mk>
