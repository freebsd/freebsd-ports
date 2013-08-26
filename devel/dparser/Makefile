# Created by: ijliao
# $FreeBSD$

PORTNAME=	dparser
PORTVERSION=	1.30
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	d-${PORTVERSION}-src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Simple but powerful tool for parsing

OPTIONS_DEFINE=	BOEHM DOCS
BOEHM_DESC=	Boehm garbage collector support

WRKSRC=		${WRKDIR}/d

EXTRACT_AFTER_ARGS=	--exclude "*my*"
USES=		gmake
MAKE_ARGS=	CC="${CC}" D_OPTIMIZE= PREFIX=${PREFIX}

MAN1=		make_dparser.1
PORTDOCS=	*
PLIST_FILES=	bin/make_dparser include/dparse.h include/dparse_tables.h \
		include/dparse_tree.h include/dsymtab.h lib/${LIBDPARSE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBOEHM}
LIB_DEPENDS+=	gc:${PORTSDIR}/devel/boehm-gc
MAKE_ARGS+=	D_USE_GC=1 \
		GC_CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"
LIBDPARSE=	libdparse_gc.a
.else
LIBDPARSE=	libdparse.a
.endif

.if ${ARCH} == "ia64"
BROKEN=		Does not build on ia64
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/make_dparser ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/make_dparser.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/dparse.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/dparse_tables.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/dparse_tree.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/dsymtab.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/${LIBDPARSE} ${PREFIX}/lib
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
