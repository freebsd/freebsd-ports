PORTNAME=		sourcehansans
PORTVERSION=		2.000
DISTVERSIONSUFFIX=	R
CATEGORIES=		chinese x11-fonts
PKGNAMESUFFIX=		-tc-otf
# Note: the following PKGNAMEPREFIX is here only for self-documenting purpose;
#       actual prefixing is done by the `chinese' category itself.
#PKGNAMEPREFIX=		zh-

MAINTAINER=		hyun@caffeinated.codes
COMMENT=		Traditional Chinese font by Adobe designed for user interfaces

LICENSE=		OFL11
LICENSE_FILE=		${WRKSRC}/LICENSE.txt

USES=			fonts
USE_GITHUB=		yes
GH_ACCOUNT=		adobe-fonts
GH_PROJECT=		source-han-sans

NO_ARCH=		yes
NO_BUILD=		yes
SUB_FILES=		pkg-message

OPTIONS_DEFINE=		HW
OPTIONS_SINGLE=		TYPE
OPTIONS_SINGLE_TYPE=	FULL SUBSET
OPTIONS_DEFAULT=	FULL
OPTIONS_SUB=		yes

HW_DESC=		Install the half-width font in addition to the full font
FULL_DESC=		Install the full font (can display all CJK)
SUBSET_DESC=		Install the subset font (can display TC only)
SUBSET_PREVENTS=	HW
SUBSET_PREVENTS_MSG=	Half-width can only be installed in addition to the full font

FULL_VARS=		FONTNAME=SourceHanSansTC SRCFONTSDIR=OTF/TraditionalChinese
SUBSET_VARS=		FONTNAME=SourceHanSansTW SRCFONTSDIR=SubsetOTF/TW

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${SRCFONTSDIR}/*.otf ${STAGEDIR}${FONTSDIR}

post-install-HW-on:
	${INSTALL_DATA} ${WRKSRC}/OTF/TraditionalChineseHW/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
