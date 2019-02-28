# $FreeBSD$

PORTNAME=		sourcehanserif
PORTVERSION=		1.001
DISTVERSIONSUFFIX=	R
CATEGORIES=		japanese x11-fonts
PKGNAMESUFFIX=		-otf
# Note: the following PKGNAMEPREFIX is here only for self-documenting purpose;
#       actual prefixing is done by the `japanese' category itself.
#PKGNAMEPREFIX=		ja-

MAINTAINER=		hyun@caffeinated.codes
COMMENT=		Japanese font by Adobe designed for user interfaces

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
SUBSET_DESC=		Install the subset font (can display Japanese only)

FULL_VARS=		FONTNAME=SourceHanSerif SRCFONTSDIR=OTF/Japanese
SUBSET_VARS=		FONTNAME=SourceHanSerifJP SRCFONTSDIR=SubsetOTF/JP

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${SRCFONTSDIR}/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
