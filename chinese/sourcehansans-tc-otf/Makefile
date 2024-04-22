CATEGORIES=		chinese x11-fonts
PKGNAMESUFFIX=		-tc-otf
# Note: the following PKGNAMEPREFIX is here only for self-documenting purpose;
#       actual prefixing is done by the `chinese' category itself.
#PKGNAMEPREFIX=		zh-

COMMENT=		Traditional Chinese font by Adobe designed for user interfaces

SUBSET_DESC=		Install the subset font (can display TC only)

FULL_VARS=		FONTNAME=SourceHanSansTC SRCFONTSDIR=OTF/TraditionalChinese
SUBSET_VARS=		FONTNAME=SourceHanSansTW SRCFONTSDIR=SubsetOTF/TW

SHS_HW_LANG=		TraditionalChinese

MASTERDIR=		${.CURDIR}/../../japanese/sourcehansans-otf

.include "${MASTERDIR}/Makefile"
