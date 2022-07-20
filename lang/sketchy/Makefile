PORTNAME=	sketchy
PORTVERSION=	20070218
PORTREVISION=	1
CATEGORIES=	lang devel lisp scheme
MASTER_SITES=	SF/sketchy-lisp/sketchy-lisp/2007-02-18

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interpreter for purely applicative Scheme

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
	${LN} -sf libsketchy.so.31 ${STAGEDIR}${PREFIX}/lib/libsketchy.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsketchy.so
	${LN} -s sketchy.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/sk.1.gz

.include <bsd.port.mk>
