# New ports collection makefile for:    mpeg_encode
# Date created:         
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mpeg_encode
PORTVERSION=	1.5b
CATEGORIES=	graphics
MASTER_SITES=	ftp://mm-ftp.CS.Berkeley.EDU/pub/multimedia/mpeg/encode/
DISTNAME=	${PKGNAME}-src

MAINTAINER=	ports@FreeBSD.org


MAN1=		mpeg_encode.1

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg_encode ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/mpeg_encode.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for i in users-guide.ps template.param
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif

.include <bsd.port.mk>
