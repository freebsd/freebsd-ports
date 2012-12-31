# $FreeBSD$

PORTNAME=	libpuzzle
PORTVERSION=	0.11
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/releases/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	A library to find similar pictures

LICENSE=	BSD

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

MAKE_JOBS_SAFE=	yes

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS COPYING NEWS README THANKS

MAN3=		libpuzzle.3 puzzle_set.3
MAN8=		puzzle-diff.8

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS	${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/THANKS ${DOCSDIR}
.endif

.include <bsd.port.mk>
