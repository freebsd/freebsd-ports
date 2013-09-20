# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	csrd
PORTVERSION=	1.0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/csrd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for Shogakukan Random House English-Japanese Dictionary

MAKEFILE=	makefile.unx
ALL_TARGET=	csrd

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csrd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/csrd.fmt ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/csrd.gai ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/doc/${PKGNAME}
	${INSTALL_DATA} ${WRKSRC}/csrd.doc ${PREFIX}/share/doc/${PKGNAME}

.include <bsd.port.mk>
