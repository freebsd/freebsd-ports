# New ports collection makefile for:	libpuzzle
# Date created:		2007-12-05
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libpuzzle
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/releases/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	A library to find similar pictures

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

MAKE_JOBS_SAFE=	yes

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS COPYING NEWS README THANKS

MAN3=		libpuzzle.3 puzzle_set.3
MAN8=		puzzle-diff.8

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS	${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/THANKS ${DOCSDIR}
.endif

.include <bsd.port.mk>
