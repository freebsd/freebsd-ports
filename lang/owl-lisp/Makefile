PORTNAME=		owl-lisp
DISTVERSIONPREFIX=	v
DISTVERSION=		0.2.2
CATEGORIES=		lang

MAINTAINER=	me@pacopascal.com
COMMENT=	Functional dialect of Scheme
WWW=		https://gitlab.com/owl-lisp/owl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USE_GITLAB=	yes
GL_PROJECT=	owl
GL_TAGNAME=	v0.2.2

MAKE_ARGS+=\
	CC="${CC}" \
	CFLAGS="${CFLAGS}" \
	PREFIX="${PREFIX}"

TEST_TARGET=fasltest test random-test

PLIST_FILES=\
	bin/ol \
	bin/ovm \
	share/man/man1/ol.1.gz \
	share/man/man1/ovm.1.gz \
	share/owl-lisp/fasl/init.fasl

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/ol
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/ovm
	${MKDIR} ${STAGEDIR}${DATADIR}/fasl
	${INSTALL_DATA} ${WRKSRC}/fasl/init.fasl ${STAGEDIR}${DATADIR}/fasl/init.fasl

.include <bsd.port.mk>
