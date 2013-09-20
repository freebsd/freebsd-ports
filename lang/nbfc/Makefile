# Created by: gahr
# $FreeBSD$

PORTNAME=	nbfc
PORTVERSION=	0.1
CATEGORIES=	lang
MASTER_SITES=	http://koeln.ccc.de/ablage/brainfuck/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	New Brainfuck Compiler

MAN1=	nbfc.1

PLIST_FILES=	bin/nbfc

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g; s|bison -y|${YACC} -|g; s|gcc|${CC} ${CFLAGS}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
