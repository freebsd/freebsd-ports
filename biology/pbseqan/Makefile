# $FreeBSD$

PORTNAME=	pbseqan
DISTVERSION=	g20171002
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Pacific Biosciences patched and stripped down SeqAn

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_PROJECT=	seqan
GH_TAGNAME=	d01138731be5d54ef4948053493408075f19e0b1

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/PacBio
	cd ${WRKSRC}/include/seqan && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/PacBio/seqan

.include <bsd.port.mk>
