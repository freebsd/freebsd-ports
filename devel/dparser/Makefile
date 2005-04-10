# ex:ts=8
# Ports collection makefile for:	dparser
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dparser
PORTVERSION=	1.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	d-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple but powerful tool for parsing

WRKSRC=		${WRKDIR}/d

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" D_OPTIMIZE=

MAN1=		make_dparser.1
PORTDOCS=	faq.html index.html manual.html
PLIST_FILES=	bin/make_dparser include/dparse.h include/dparse_tables.h \
		include/dsymtab.h lib/${LIBDPARSE}

.if defined(WITH_GC)
LIB_DEPENDS+=	gc:${PORTSDIR}/devel/boehm-gc
MAKE_ARGS+=	D_USE_GC=1 \
		GC_CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"
LIBDPARSE=	libdparse_gc.a
.else
LIBDPARSE=	libdparse.a
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/make_dparser ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/make_dparser.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/dparse.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/dparse_tables.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/dsymtab.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/${LIBDPARSE} ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
