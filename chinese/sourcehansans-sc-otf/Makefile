CATEGORIES=		chinese x11-fonts
PKGNAMESUFFIX=		-sc-otf
# Note: the following PKGNAMEPREFIX is here only for self-documenting purpose;
#       actual prefixing is done by the `chinese' category itself.
#PKGNAMEPREFIX=		zh-

COMMENT=		Simplified Chinese font by Adobe designed for user interfaces

SUBSET_DESC=		Install the subset font (can display SC only)

FULL_VARS=		FONTNAME=SourceHanSansSC SRCFONTSDIR=OTF/SimplifiedChinese
SUBSET_VARS=		FONTNAME=SourceHanSansCN SRCFONTSDIR=SubsetOTF/CN

SHS_HW_LANG=		SimplifiedChinese

MASTERDIR=		${.CURDIR}/../../japanese/sourcehansans-otf

.include "${MASTERDIR}/Makefile"
