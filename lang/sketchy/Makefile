# Created by: Nils M Holm <nmh@t3x.org>
# $FreeBSD$

PORTNAME=	sketchy
PORTVERSION=	20070218
CATEGORIES=	lang devel lisp scheme
MASTER_SITES=	http://www.t3x.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interpreter for purely applicative Scheme

USES=		uidfix
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/sketchy.h
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/src/pp.scm
	@${REINPLACE_CMD} -E \
		-e '/ln -sf/! s,(BIN|DOC|INC|LIB|MAN|SHR)DIR),DESTDIR)$$(&,' \
		-e '/ln -sf/ s,LIBDIR,DESTDIR)$$(&,2' \
		${WRKSRC}/Makefile

post-install:
	@${LN} -s ${MANPREFIX}/man/man1/sketchy.1.gz \
		${STAGEDIR}${MANPREFIX}/man/man1/sk.1.gz

.include <bsd.port.mk>
