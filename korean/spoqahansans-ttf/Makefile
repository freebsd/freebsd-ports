PORTNAME=		spoqahansans
DISTVERSIONPREFIX=	v
DISTVERSION=		2.1.2
CATEGORIES=		korean x11-fonts
MASTER_SITES=		https://github.com/spoqa/spoqa-han-sans/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
# Note: the following PKGNAMEPREFIX is here only for self-documenting purpose;
#       actual prefixing is done by the `korean' category itself.
#PKGNAMEPREFIX=		ko-
PKGNAMESUFFIX=		-ttf
DISTNAME=		SpoqaHanSans_all

MAINTAINER=		hyun@caffeinated.codes
COMMENT=		Korean custom font based on Noto Sans and Lato

LICENSE=		OFL11
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			fonts zip

FONTNAME=		SpoqaHanSans
NO_ARCH=		yes
NO_BUILD=		yes
SUB_FILES=		pkg-message

OPTIONS_SINGLE=		TYPE
OPTIONS_SINGLE_TYPE=	ORIGINAL SUBSET
OPTIONS_DEFAULT=	ORIGINAL

ORIGINAL_DESC=		Install original font (supports Korean and Japanese)
SUBSET_DESC=		Install subset font (supports 2,574 Korean glyphs)

ORIGINAL_VARS=		SRCFONTSDIR=SpoqaHanSans_original
SUBSET_VARS=		SRCFONTSDIR=SpoqaHanSans_subset

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${SRCFONTSDIR}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
