# New ports collection makefile for:	io
# Date created:		4 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	io
PORTVERSION=	0.0.2005.10.17
CATEGORIES=	lang
MASTER_SITES=	http://io.urbanape.com/release/ \
		http://www.sigusr1.org/~steve/
DISTNAME=	IoFull-${PORTVERSION:S/0.0.//:S/./-/g}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Small prototype-based programming language

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		event-1.1a.1:${PORTSDIR}/devel/libevent

USE_GMAKE=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/release/${DISTNAME}/
MAKE_ENV=	INCS="-I${LOCALBASE}/include" LIBLOCAL="-L${LOCALBASE}/lib"
BINDINGS_DEACTIVATE=	Font Image ObjcBridge OpenGL SGML SQLite SQLite3

pre-patch:
	${RM} ${WRKSRC}/vm/base/DynLib_OSX.c
	cd ${WRKSRC}/libs && for mod in *; do \
		if [ $$mod != "zlib" ]; then \
			${RM} -fr $$mod; \
		fi; \
	done
	cd ${WRKSRC}/bindings; ${RM} -fr ${BINDINGS_DEACTIVATE}

	for mkf in `${FIND} ${WRKSRC} -iname Makefile`; do \
		${REINPLACE_CMD} \
			-e 's,^CFLAGS.*$$,CFLAGS+=$${INCS} $${INCLUDE},g' \
			-e 's,^\(LFLAGS.*\)$$,\1 $${LIBLOCAL},g' \
			-e 's,^CC=\(.*\)$$,CC?=\1,g' \
			$$mkf; \
	done

	${REINPLACE_CMD} \
		-e 's,^\( *options := "\).*$$,\1${CFLAGS} -I${LOCALBASE}/include -DSANE_POPEN -DIOBINDINGS",' \
		-e 's,\( -lIoVM\),\1 -lncurses ,' \
		${WRKSRC}/_build.io

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vm/io ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vm/io2c ${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/vm/_libs/libIoVM.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/bindings/*/*.a ${PREFIX}/lib

.for incldir in . SkipDB base
	${MKDIR} ${PREFIX}/include/io/${incldir}
	${INSTALL_DATA} ${WRKSRC}/vm/_include/${incldir}/*.h ${PREFIX}/include/io/${incldir}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/_docs/* ${DOCSDIR}

.for subdir in ioCode new sampleCode docgen tests unitTests
	${MKDIR} ${EXAMPLESDIR}/${subdir}
	${TAR} -C ${WRKSRC}/vm/_${subdir} -cf - . | \
		${TAR} -C ${EXAMPLESDIR}/${subdir} -xf -
.endfor
.endif

.include <bsd.port.mk>
