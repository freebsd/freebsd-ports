# New ports collection makefile for:	io
# Date created:		4 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	io
PORTVERSION=	0.0.2006.01.27
CATEGORIES=	lang
MASTER_SITES=	http://io.urbanape.com/release/ \
		http://www.sigusr1.org/~steve/
DISTNAME=	IoFull-${PORTVERSION:S/0.0.//:S/./-/g}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Small prototype-based programming language

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		event-1.1a.1:${PORTSDIR}/devel/libevent

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/release/${DISTNAME}/
MAKE_ENV=	INCS="-I${LOCALBASE}/include" LIBLOCAL="-L${LOCALBASE}/lib"
BINDINGS_DEACTIVATE=	Font Image ObjcBridge OpenGL SGML SQLite SQLite3

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64 or sparc64
.endif

.if ${OSVERSION} < 500000
USE_GCC=	3.4+
.endif

pre-patch:
	${FIND} ${WRKSRC} -name '.DS_Store*' -delete

	${RM} ${WRKSRC}/vm/base/DynLib_OSX.c
	cd ${WRKSRC}/libs && for mod in *; do \
		if [ $$mod != "zlib" ]; then \
			${RM} -fr $$mod; \
		fi; \
	done
	cd ${WRKSRC}/bindings; ${RM} -fr ${BINDINGS_DEACTIVATE}

	for mkf in `${FIND} ${WRKSRC} -iname Makefile`; do \
		${REINPLACE_CMD} \
			-e 's,^CFLAGS.*$$,CFLAGS+=-g $${INCS} $${INCLUDE},g' \
			-e 's,^\(LFLAGS.*\)$$,\1 $${LIBLOCAL},g' \
			-e 's,^CC=\(.*\)$$,CC?=\1,g' \
			$$mkf; \
	done

	${REINPLACE_CMD} \
		-e 's,^\( *options := "\).*$$,\1${CFLAGS} -I${LOCALBASE}/include -DSANE_POPEN -DIOBINDINGS",' \
		-e 's,\( -lIoVM\), -L${LOCALBASE}/lib \1 -lncurses ,' \
		${WRKSRC}/_build.io

	${ECHO_CMD} 'Binding clone do (dependsOnLib("z"))' \
		> ${WRKSRC}/bindings/Zlib/_build.io

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -delete
.if ${OSVERSION} < 500000
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's/<stdint.h>/<inttypes.h>/' vm/base/_new/Array/Array.h vm/base/_new/Data.h vm/base/Common.h vm/base/NEW_stdint.h
.endif

do-install:
.for fname in vm/io2c vm/io binaries/ioDesktop binaries/ioServer
	${INSTALL_PROGRAM} ${WRKSRC}/${fname} ${PREFIX}/bin
.endfor

	${INSTALL_DATA} ${WRKSRC}/vm/_libs/libIoVM.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/bindings/*/*.a ${PREFIX}/lib

.for incldir in . SkipDB base
	${MKDIR} ${PREFIX}/include/io/${incldir}
	${INSTALL_DATA} ${WRKSRC}/vm/_include/${incldir}/*.h ${PREFIX}/include/io/${incldir}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/_docs -cf - . | ${TAR} -C ${DOCSDIR} -xf -

.for subdir in ioCode new sampleCode docgen unitTests
	${MKDIR} ${EXAMPLESDIR}/${subdir}
	${TAR} -C ${WRKSRC}/vm/_${subdir} -cf - . | \
		${TAR} -C ${EXAMPLESDIR}/${subdir} -xf -
.endfor
.endif

.include <bsd.port.post.mk>
