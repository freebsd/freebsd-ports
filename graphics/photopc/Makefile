# New ports collection makefile for:	photopc-1.6
# Date created:		11 October 1997
# Whom:			Douglas Carmichael <dcarmich@mcs.com>
#
# $FreeBSD$
#

PORTNAME=	photopc
PORTVERSION=	3.07
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility to manage an Epson PhotoPC 500 digital camera

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		epinfo.1 photopc.1
PORTDOCS=	protocol.htm usage.htm
PLIST_FILES=	bin/epinfo bin/photopc include/eph_io.h lib/libeph_io.a

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
