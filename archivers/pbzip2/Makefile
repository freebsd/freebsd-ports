# Created by: ijliao
# $FreeBSD$

PORTNAME=	pbzip2
PORTVERSION=	1.1.6
CATEGORIES=	archivers
MASTER_SITES=	http://compression.ca/pbzip2/
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Parallel BZIP2

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

MAN1=		pbzip2.1
MLINKS=		pbzip2.1 pbunzip2.1

USES=		gmake

PLIST_FILES=	bin/pbzip2 bin/pbunzip2

post-patch:
	@${REINPLACE_CMD} \
		-e 's,-O2,${CXXFLAGS},; \
		s,^CC,#CC,; \
		s,CC,CXX,' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${LN} -sf ${PORTNAME} ${PREFIX}/bin/pbunzip2
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
