# ex:ts=8
# Ports collection makefile for:	exiftags
# Date created:			Sep 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	exiftags
PORTVERSION=	0.96
CATEGORIES=	graphics
MASTER_SITES=	http://johnst.org/sw/exiftags/

MAINTAINER=	ports@FreeBSD.org

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}"

MAN1=	exifcom.1 exiftags.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exifcom ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/exiftags ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/exifcom.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/exiftags.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
