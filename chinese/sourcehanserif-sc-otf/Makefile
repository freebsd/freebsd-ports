PORTNAME=		sourcehanserif
PORTVERSION=		1.001
PORTREVISION=		1
DISTVERSIONSUFFIX=	R
CATEGORIES=		chinese x11-fonts
PKGNAMESUFFIX=		-sc-otf
# Note: the following PKGNAMEPREFIX is here only for self-documenting purpose;
#       actual prefixing is done by the `chinese' category itself.
#PKGNAMEPREFIX=		zh-

MAINTAINER=		hyun@caffeinated.codes
COMMENT=		Simplified Chinese font by Adobe designed for user interfaces

LICENSE=		OFL11
LICENSE_FILE=		${WRKSRC}/LICENSE.txt

USES=			fonts
USE_GITHUB=		yes
GH_ACCOUNT=		adobe-fonts
GH_PROJECT=		source-han-serif

NO_ARCH=		yes
NO_BUILD=		yes
SUB_FILES=		pkg-message

OPTIONS_SINGLE=		TYPE
OPTIONS_SINGLE_TYPE=	FULL SUBSET
OPTIONS_DEFAULT=	FULL
OPTIONS_SUB=		yes

FULL_DESC=		Install the full font (can display all CJK)
SUBSET_DESC=		Install the subset font (can display SC only)

FULL_VARS=		FONTNAME=SourceHanSerifSC SRCFONTSDIR=OTF/SimplifiedChinese
SUBSET_VARS=		FONTNAME=SourceHanSerifCN SRCFONTSDIR=SubsetOTF/CN

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${SRCFONTSDIR}/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
