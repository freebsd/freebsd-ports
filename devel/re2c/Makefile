# New ports collection makefile for:	re2c
# Date created:		14 May 1998
# Whom:			Eivind Eklund <eivind@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	re2c
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.tildeslash.org/re2c/ \
		http://www.tobez.org/download/port-mirrors/devel/re2c/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compile regular expression to C (much faster final code than flex)

USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=		re2c.1

ALL_TARGET=	default

pre-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS.*$$|CFLAGS+=-Wall -I. -Wno-unused -Wno-parentheses|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/parser.cc ${WRKSRC}/parser.y

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/re2c ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/re2c.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/re2c
	${INSTALL_DATA} ${WRKSRC}/doc/loplas.ps.gz ${WRKSRC}/doc/sample.bib \
		${PREFIX}/share/doc/re2c

.include <bsd.port.mk>
