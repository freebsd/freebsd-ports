# ex:ts=8
# Ports collection makefile for:	pbzip2
# Date created:			Dec 7, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pbzip2
PORTVERSION=	0.9.2
CATEGORIES=	archivers
MASTER_SITES=	http://compression.ca/pbzip2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel BZIP2

USE_REINPLACE=	yes

PLIST_FILES=	bin/pbzip2

post-patch:
	@${REINPLACE_CMD} -e "s,-pthread -lpthread,${PTHREAD_LIBS},g" \
		-e "s,-O3,${CXXFLAGS}," \
		-e "s,^CC,#CC," \
		-e "s,CC,CXX," ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
