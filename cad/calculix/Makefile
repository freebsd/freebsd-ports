# New ports collection makefile for:	CalculiX
# Date created:		19 April 2003
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	CalculiX
PORTVERSION=	1.1
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
DISTFILES=	ccx_${PORTVERSION}.src.tar.gz cgx_${PORTVERSION}.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	ccx_${PORTVERSION}.ps.tar.gz cgx_${PORTVERSION}.ps.tar.gz \
		ccx_${PORTVERSION}.htm.tar.gz cgx_${PORTVERSION}.htm.tar.gz
.endif
.ifdef WITH_EXAMPLES
DISTFILES+=	ccx_${PORTVERSION}.test.tar.gz
.endif
DIST_SUBDIR=	calculix

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A Three-Dimensional Structural Finite Element Program

# These are required to build Crunchix (ccx)
BUILD_DEPENDS=	${LOCALBASE}/lib/libspooles.a:${PORTSDIR}/math/spooles \
		${LOCALBASE}/lib/libarpack.a:${PORTSDIR}/math/arpack \
		${LOCALBASE}/lib/libf77blas.a:${PORTSDIR}/math/atlas

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_MESA=	yes
USE_REINPLACE=	yes
BLAS_LIBS=	-lf77blas -latlas
BROWSER?=	mozilla
PSVIEWER?=	gv

.if !defined(WITH_EXAMPLES)
PLIST_SUB=      WITH_EXAMPLES="@comment "
.else
PLIST_SUB=      WITH_EXAMPLES=""
.endif

.ifndef (WITH_EXAMPLES)
pre-everything::
	@${ECHO} "You can define WITH_EXAMPLES=yes to install example files"
.endif

pre-build:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%CC%%+${CC}+g ; \
	s+%%BLAS_LIBS%%+${BLAS_LIBS}+ ; \
	s+%%LOCALBASE%%+${LOCALBASE}+g;' \
		${WRKSRC}/ccx_${PORTVERSION}/src/Makefile
	@${REINPLACE_CMD} -e 's+%%X11BASE%%+${X11BASE}+g; \
	s+%%PTHREAD_CFLAGS%%+${PTHREAD_CFLAGS}+g; \
	s+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g;' \
		${WRKSRC}/cgx_${PORTVERSION}/src/Makefile
	@${REINPLACE_CMD} -e 's+%%DOCSDIR%%+${DOCSDIR}+g; \
	s+"netscape"+"${BROWSER}"+ ; \
	s+"ghostview"+"${PSVIEWER}"+ ;' \
		${WRKSRC}/cgx_${PORTVERSION}/src/cgx.h

do-build:
	@(cd ${WRKSRC}/ccx_${PORTVERSION}/src; ${SETENV} ${MAKE_ENV} $(MAKE) )
	@(cd ${WRKSRC}/cgx_${PORTVERSION}/src; ${SETENV} ${MAKE_ENV} $(MAKE) )

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ccx_${PORTVERSION}/src/ccx_${PORTVERSION} \
	  ${PREFIX}/bin/ccx
	@${INSTALL_PROGRAM} ${WRKSRC}/cgx_${PORTVERSION}/src/cgx \
	  ${PREFIX}/bin/cgx
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/ccx
	@${INSTALL_DATA} ${WRKSRC}/ccx_${PORTVERSION}/doc/ccx/* \
	  ${DOCSDIR}/ccx
	@${MKDIR} ${DOCSDIR}/cgx
	@${INSTALL_DATA} ${WRKSRC}/cgx_${PORTVERSION}/doc/cgx/* \
	  ${DOCSDIR}/cgx
	@${INSTALL_DATA} ${WRKSRC}/ccx_${PORTVERSION}/doc/*.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/cgx_${PORTVERSION}/doc/*.ps ${DOCSDIR}
	@${GZIP_CMD} ${DOCSDIR}/*.ps
.endif
.ifdef WITH_EXAMPLES
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} cf - -C ${WRKSRC}/cgx_${PORTVERSION}/examples . | ${TAR} xf - -C ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/test
	@${TAR} cf - -C ${WRKSRC}/ccx_${PORTVERSION}/test . | ${TAR} xf - -C ${EXAMPLESDIR}/test
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
