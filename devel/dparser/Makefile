# Created by: ijliao
# $FreeBSD$

PORTNAME=	dparser
PORTVERSION=	1.31
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple but powerful tool for parsing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	jplevyak

EXTRACT_AFTER_ARGS=	--exclude "*my*"
MAKE_ARGS=	CC="${CC}" D_OPTIMIZE= PREFIX=${PREFIX}

PORTDOCS=	*
PLIST_FILES=	bin/make_dparser include/dparse.h include/dparse_tables.h \
		include/dparse_tree.h include/dsymtab.h lib/${LIBDPARSE} \
		man/man1/make_dparser.1.gz

OPTIONS_DEFINE=	BOEHM DOCS
BOEHM_DESC=	Boehm garbage collector support

BOEHM_LIB_DEPENDS=	libgc.so:devel/boehm-gc
BOEHM_MAKE_ARGS=	D_USE_GC=1 LOCALBASE=${LOCALBASE}
BOEHM_VARS=		LIBDPARSE=libdparse_gc.a
BOEHM_VARS_OFF=		LIBDPARSE=libdparse.a

TEST_TARGET=	test

post-patch:
	@${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/D_BUILD_VERSION

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/make_dparser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/make_dparser.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/dparse.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/dparse_tables.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/dparse_tree.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/dsymtab.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/${LIBDPARSE} ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
