# New ports collection makefile for:	re2c
# Date created:		14 May 1998
# Whom:			Eivind Eklund <eivind@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	re2c
PORTVERSION=	0.9.1
CATEGORIES=	devel
MASTER_SITES=	http://www.tildeslash.org/re2c/ \
		http://www.tobez.org/download/port-mirrors/devel/re2c/

MAINTAINER=	eivind@FreeBSD.org

USE_GMAKE=	yes

MAN1=		re2c.1

ALL_TARGET=	default

pre-patch:
	@${PERL} -pi -e 's|^CFLAGS.*$$|CFLAGS+=-Wall -I. -Wno-unused -Wno-parentheses|' ${WRKSRC}/Makefile
	@${PERL} -pi -e 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/parser.cc ${WRKSRC}/parser.y

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/re2c ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/re2c.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/re2c
	${INSTALL_DATA} ${WRKSRC}/doc/loplas.ps.gz ${WRKSRC}/doc/sample.bib \
		${PREFIX}/share/doc/re2c

.include <bsd.port.mk>
