# Created by: Nils M Holm <nmh@t3x.org>
# $FreeBSD$

PORTNAME=	sketchy
PORTVERSION=	20070218
PORTREVISION=	1
CATEGORIES=	lang devel lisp scheme
MASTER_SITES=	http://www.t3x.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interpreter for purely applicative Scheme

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		uidfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/sketchy.h
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/src/pp.scm
	@${REINPLACE_CMD} -E \
		-e '/ln -sf/! s,(BIN|DOC|INC|LIB|MAN|SHR)DIR),DESTDIR)$$(&,' \
		-e '/ln -sf/ s,LIBDIR,DESTDIR)$$(&,2' \
		${WRKSRC}/Makefile

post-install:
	cd ${STAGEDIR} && ${FIND} . -not -type d -exec ls -ld {} \;
	${LN} -sf libsketchy.so.31 ${STAGEDIR}${PREFIX}/lib/libsketchy.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsketchy.so
	${LN} -s ${MANPREFIX}/man/man1/sketchy.1.gz \
		${STAGEDIR}${MANPREFIX}/man/man1/sk.1.gz

.include <bsd.port.mk>
