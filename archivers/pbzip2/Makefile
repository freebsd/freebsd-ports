# ex:ts=8
# Ports collection makefile for:	pbzip2
# Date created:			Dec 7, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pbzip2
PORTVERSION=	1.0.2
CATEGORIES=	archivers
MASTER_SITES=	http://compression.ca/pbzip2/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Parallel BZIP2

PLIST_FILES=	bin/pbzip2 bin/pbunzip2

MAN1=	pbzip2.1
MLINKS=	pbzip2.1 pbunzip2.1

post-patch:
	@${REINPLACE_CMD} \
		-e 's,-pthread -lpthread,${PTHREAD_LIBS},g; \
		s,-O3,${CXXFLAGS},; \
		s,^CC,#CC,; \
		s,CC,CXX,' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,PRIu64 "Lu",PRIu64 Lu,;s,"PRIu64",#PRIu64,g' \
		${WRKSRC}/pbzip2.cpp

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${LN} -sf ${PORTNAME} ${PREFIX}/bin/pbunzip2
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
