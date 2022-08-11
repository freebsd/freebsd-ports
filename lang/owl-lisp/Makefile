PORTNAME=	owl-lisp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.23
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Functional dialect of Scheme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USE_GITLAB=	yes
GL_PROJECT=	owl
GL_COMMIT=	079f58f45039805517b9b880feec050e151c52b3

MAKE_ARGS+=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		PREFIX="${PREFIX}"

TEST_TARGET=	fasltest test random-test

PLIST_FILES=	bin/ol \
		bin/ovm \
		share/man/man1/ol.1.gz \
		share/man/man1/ovm.1.gz \
		share/owl-lisp/fasl/init.fasl

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/fasl
	${INSTALL_DATA} ${WRKSRC}/fasl/init.fasl ${STAGEDIR}${DATADIR}/fasl/init.fasl

.include <bsd.port.mk>
