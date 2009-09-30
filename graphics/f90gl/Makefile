# New ports collection makefile for:	f90gl
# Date created:				2007/7/21
# Whom:					Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	f90gl
PORTVERSION=	1.2.13
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://math.nist.gov/f90gl/ \
		http://math.nist.gov/~WMitchell/papers/:doc
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	nistir6134.ps.gz:doc nistir6134.pdf:doc \
		errata
.endif
DIST_SUBDIR=    ${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Official Fortran 90 bindings for OpenGL

USE_GL=		glut glu
USE_XORG=	xaw
USE_LDCONFIG=	yes
USE_FORTRAN=	yes
FNAME=		UNDERSCORE

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "amd64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif
SVERSION=1
WRKSRC_SHARED=${WRKSRC}_shared
CFLAGS_SHARED=${CFLAGS} ${FPIC}
FFLAGS_SHARED=${CFLAGS} ${FPIC}
.if !defined(WITH_EXAMPLES)
PLIST_SUB=	WITH_EXAMPLES="@comment "
.else
PLIST_SUB=	WITH_EXAMPLES=""
.endif

.if !defined (OPENGL_DISPLAY)
EXTRA_PATCHES=	${PATCHDIR}/extra-disable-mkfppinc
.endif

post-patch:
	${CP} -r ${WRKSRC} ${WRKSRC_SHARED}

pre-build:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' \
			-e 's|%%CFLAGS%%|${CFLAGS}|g' \
			-e 's|%%FC%%|${FC}|g' \
			-e 's|%%FFLAGS%%|${FFLAGS}|g' \
			-e 's|%%FNAME%%|${FNAME}|g' \
			-e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/mf8lim7

	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' \
			-e 's|%%CFLAGS%%|${CFLAGS_SHARED}|g' \
			-e 's|%%FC%%|${FC}|g' \
			-e 's|%%FFLAGS%%|${FFLAGS_SHARED}|g' \
			-e 's|%%FNAME%%|${FNAME}|g' \
			-e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC_SHARED}/mf8lim7

	@${REINPLACE_CMD} -e 's|%%WRKSRC%%|${WRKSRC}|g' \
			-e 's|%%FC%%|${FC}|g' \
			-e 's|%%FFLAGS%%|${FFLAGS}|g' \
			-e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC_SHARED}/examples/mf8lnt

do-build:
.if !defined (OPENGL_DISPLAY)
	${CP} ${FILESDIR}/glopt.h ${WRKSRC}/util
	${CP} ${FILESDIR}/glopt.h ${WRKSRC_SHARED}/util
.endif
	cd ${WRKSRC}                 ; ${MAKE} -f mf8lim7
	cd ${WRKSRC_SHARED}          ; ${MAKE} -f mf8lim7
	cd ${WRKSRC_SHARED}/examples ; ${MAKE} -f mf8lnt

post-build:
	cd ${WRKSRC_SHARED}/lib ; for i in `ls *.a | ${SED}  's/\.a//' `; do \
		ld -Bshareable -o $${i}.so.${SVERSION} -x -soname $${i}.so.${SVERSION} --whole-archive $${i}.a ;\
		${LN} -s $${i}.so.${SVERSION} $${i}.so ;\
	done

do-install:
	${MKDIR} ${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/*	${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/lib/*.a	${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC_SHARED}/lib/*.so.${SVERSION}	${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC_SHARED}/lib/*.so	${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in nistir6134.ps.gz nistir6134.pdf errata
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${i} ${DOCSDIR}
.endfor
.for i in INSTALL USRGUIDE README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.if defined(WITH_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} cf - -C ${WRKSRC_SHARED}/examples . | ${TAR} xf - -C ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
