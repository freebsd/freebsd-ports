# Ports collection makefile for:  culmus
# Date created:			  11 Apr 2003
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	culmus
PORTVERSION=	0.90
CATEGORIES=	hebrew
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	yonatan@xpert.com
COMMENT=	Free Hebrew Type1 fonts

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients

USE_X_PREFIX=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/X11/fonts/culmus
.	for file in Aharoni-Bold Aharoni-BoldOblique Aharoni-Book Aharoni-BookOblique Caladings David-Bold David-Medium David-MediumItalic Drugulin-Bold Drugulin-BoldItalic Ellinia-Bold Ellinia-BoldItalic Ellinia-Light Ellinia-LightItalic FrankRuehl-Bold FrankRuehl-BoldOblique FrankRuehl-Medium FrankRuehl-MediumOblique KtavYad-BoldItalic KtavYad-MediumItalic MiriamMono-Bold MiriamMono-BoldOblique MiriamMono-Book MiriamMono-BookOblique Nachlieli-Bold Nachlieli-BoldOblique Nachlieli-Light Nachlieli-LightOblique
		${INSTALL_DATA} ${WRKSRC}/${file}.afm ${PREFIX}/lib/X11/fonts/culmus
		${INSTALL_DATA} ${WRKSRC}/${file}.pfa ${PREFIX}/lib/X11/fonts/culmus
.	endfor
	@cd ${WRKSRC}; ${PREFIX}/bin/mkfontscale; ${PREFIX}/bin/mkfontdir
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/lib/X11/fonts/culmus
	${INSTALL_DATA} ${WRKSRC}/fonts.scale ${PREFIX}/lib/X11/fonts/culmus

post-install:
	@${SED} "s|PREFIX|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.mk>
