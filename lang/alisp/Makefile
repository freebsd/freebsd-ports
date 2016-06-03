# Created by: Nils M Holm <nmh@t3x.org>
# $FreeBSD$

PORTNAME=	alisp
PORTVERSION=	20060917
CATEGORIES=	lang devel lisp
MASTER_SITES=	http://t3x.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interpreter for purely symbolic LISP

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		uidfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:	.SILENT
	${REINPLACE_CMD} -E -e 's/cc/$$(CC)/' \
		-e '/^CFLAGS/{s/=/+=/;s/-g//;s/-O//;}' \
		-e '/strip alisp/d' \
		-e '/install.*alisp /s/install/& ${STRIP}/' \
		-e 's,(BIN|DOC|INC|LIB|MAN|SHR)DIR),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/alisp.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libalisp.so

.include <bsd.port.mk>
