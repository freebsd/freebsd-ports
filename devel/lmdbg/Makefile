PORTNAME=	lmdbg
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Lightweight malloc debugger
WWW=		https://sourceforge.net/projects/lmdbg/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

DEPRECATED=	Depends on expiring devel/mk-configure
EXPIRATION_DATE=2025-09-30

BUILD_DEPENDS=	mk-configure>=0.24:devel/mk-configure
LIB_DEPENDS=	libJudy.so:devel/judy
RUN_DEPENDS=	runawk:lang/runawk \
		${LOCALBASE}/bin/pipestatus:devel/pipestatus

USE_LDCONFIG=	yes

MKCMAKE?=	${LOCALBASE}/bin/mkcmake

PORTDOCS=	LICENSE NEWS README TODO

MKCMAKE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include
MKCMAKE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib
MKCMAKE_ENV+=	MANDIR=${PREFIX}/share/man

INSTALL_TARGET=	install install-doc

OPTIONS_DEFINE=	DOCS

do-build:
	${SETENV} ${MKCMAKE_ENV} ${MKCMAKE} -C ${WRKSRC}

do-install:
	${SETENV} ${MKCMAKE_ENV} DESTDIR=${STAGEDIR} \
		${MKCMAKE} -C ${WRKSRC} ${INSTALL_TARGET}

do-test:
	${SETENV} ${MKCMAKE_ENV} ${MKCMAKE} -C ${WRKSRC} test

.include <bsd.port.mk>
