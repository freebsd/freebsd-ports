# Created by: dbader@ece.unm.edu
# $FreeBSD$

PORTNAME=	grappa
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.cs.unm.edu/~moret/GRAPPA/
DISTNAME=	GRAPPA20

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Genome Rearrangements Analysis and Phylogeny Software

LICENSE=	GPLv2

USES=		gmake

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

PLIST_FILES=	bin/grappa bin/invdist bin/distmat

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} grappa ${STAGEDIR}${PREFIX}/bin)
	${LN} -sf grappa ${STAGEDIR}${PREFIX}/bin/invdist
	${LN} -sf grappa ${STAGEDIR}${PREFIX}/bin/distmat

.include <bsd.port.mk>
