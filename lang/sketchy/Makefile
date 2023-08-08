PORTNAME=	sketchy
PORTVERSION=	20070218
PORTREVISION=	1
CATEGORIES=	lang devel lisp scheme
MASTER_SITES=	SF/sketchy-lisp/sketchy-lisp/2007-02-18

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Interpreter for purely applicative Scheme
WWW=		http://sketchy-lisp.sourceforge.net/

USES=		uidfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

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

.include <bsd.port.post.mk>
