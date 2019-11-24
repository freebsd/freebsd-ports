# $FreeBSD$

PORTNAME=	pbseqan
DISTVERSION=	g20171011
CATEGORIES=	biology

# As of March 2018, unanimity is no longer open source.
# See https://github.com/PacificBiosciences/ccs.
MAINTAINER=     ports@FreeBSD.org
COMMENT=	Pacific Biosciences patched and stripped down SeqAn

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream merged into SeqAn project: Use biology/seqan

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_PROJECT=	seqan
GH_TAGNAME=	21d95d737d8decb5cc3693b9065d81e831e7f57d

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/PacBio
	cd ${WRKSRC}/include/seqan && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/PacBio/seqan

.include <bsd.port.mk>
