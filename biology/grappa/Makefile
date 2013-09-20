# Created by: dbader@ece.unm.edu
# $FreeBSD$

PORTNAME=	grappa
PORTVERSION=	2.0
CATEGORIES=	biology
MASTER_SITES=	http://www.cs.unm.edu/~moret/GRAPPA/
DISTNAME=	GRAPPA20

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Genome Rearrangements Analysis and Phylogeny Software

USE_GMAKE=	yes

PLIST_FILES=	bin/grappa bin/invdist bin/distmat

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grappa ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/grappa ${PREFIX}/bin/invdist
	${LN} -sf ${PREFIX}/bin/grappa ${PREFIX}/bin/distmat

.include <bsd.port.mk>
