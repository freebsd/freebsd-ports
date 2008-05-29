# New ports collection Makefile for:	nbfc
# Date created:				29 May 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	nbfc
PORTVERSION=	0.1
CATEGORIES=	lang
MASTER_SITES=	http://koeln.ccc.de/ablage/brainfuck/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	New Brainfuck Compiler

MAN1=	nbfc.1

PLIST_FILES=	bin/nbfc

post-patch:
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g;s|bison -y|yacc -|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
