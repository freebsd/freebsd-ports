CATEGORIES=		korean x11-fonts
# Note: the following PKGNAMEPREFIX is here only for self-documenting purpose;
#       actual prefixing is done by the `korean' category itself.
#PKGNAMEPREFIX=		ko-

COMMENT=		Korean font by Adobe designed for user interfaces

SUBSET_DESC=		Install the subset font (can display Korean only)

FULL_VARS=		FONTNAME=SourceHanSansK SRCFONTSDIR=OTF/Korean
SUBSET_VARS=		FONTNAME=SourceHanSansKR SRCFONTSDIR=SubsetOTF/KR

SHS_HW_LANG=		Korean

MASTERDIR=		${.CURDIR}/../../japanese/sourcehansans-otf

.include "${MASTERDIR}/Makefile"
