# Created by: The 244th namelessness at 2ch.net
# $FreeBSD$

PORTNAME=	mplus
PORTVERSION=	2.2.4
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SFJP/${PORTNAME}-fonts/5030/
PKGNAMEPREFIX=	ja-font-
PKGNAMESUFFIX=	-bitmap
DISTNAME=	${PORTNAME}_bitmap_fonts-2.2.4

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	M+ Bitmap fonts

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts
FONTNAME=	misc
NO_BUILD=	yes
NO_ARCH=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	FONTSALIAS="${DATADIR}/fonts.alias"
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	INSTALL_E LICENSE_E README_E \
		INSTALL_J LICENSE_J README_J

OPTIONS_DEFINE=	DOCS

post-extract:
	cd ${WRKSRC} && \
	    ${CAT} fonts_e/fonts.alias fonts_e/euro/fonts.alias \
	    fonts_j/fonts.alias | ${SORT} -r > ${WRKDIR}/fonts.alias

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && \
	    ${SETENV} DESTDIR="${STAGEDIR}${DATADIR}" \
	    ${SH} ${WRKSRC}/install_mplus_fonts
	${INSTALL_DATA} ${WRKDIR}/fonts.alias ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && \
	    ${LN} -s -f ../../../${DATADIR_REL}/*.pcf.gz .

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
