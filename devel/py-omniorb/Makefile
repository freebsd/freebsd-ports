# New ports collection makefile for:	py-omniorb
# Date created:		14 November 2000
# Whom:			Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	omniorb
PORTVERSION= 	1.3
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.uk.research.att.com/pub/omniORB/omniORBpy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	omniORBpy_${PORTVERSION:S/./_/g}

MAINTAINER=	johann@egenetics.com

LIB_DEPENDS=	omniORB3.0:${PORTSDIR}/devel/omniORB
RUN_DEPENDS=	omniidl:${PORTSDIR}/devel/omniORB
# A pre-built omniORB3 source tree is required to build omniORBpy;
# see also the "post-extract" target below.
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/omniORB:build

USE_PYTHON=	yes
USE_NEWGCC=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	export
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/omni
BUILD_WRKSRC=	${WRKSRC}/src/lib/omniORBpy
MAKE_ENV+=	CDEBUGFLAGS="${CFLAGS}" CXXDEBUGFLAGS="${CXXFLAGS}" \
		BSD_INSTALL="${INSTALL}" PYTHON_CMD="${PYTHON_CMD}" \
		MKDIR="${MKDIR}"
ONLY_FOR_ARCHS=	i386
CONFIG_TARGET=	x86_freebsd_4.0
CPIO=		cpio --quiet -pdum -R

MODULEDIRS=	CosNaming CosNaming__POA omniORB
DOCDIR=		${PREFIX}/share/doc/omniORBpy
EGDIR=		${PREFIX}/share/examples/omniORBpy

post-extract:
	@ ${CP} -pfR ${PORTSDIR}/devel/omniORB/work/omni ${WRKDIR}
	@ ${MV} -f ${WRKDIR}/omniORBpy ${WRKSRC}/src/lib/

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/lib/python/omniidl_be/python.py* \
	  ${PYTHON_SITELIBDIR}/omniidl_be
	@ cd ${WRKSRC}/lib/python && find ${MODULEDIRS} \
	  | ${CPIO} ${BINOWN}:${BINGRP} ${PYTHON_SITELIBDIR}
	@ cd ${WRKSRC}/lib/${CONFIG_TARGET} && find _omnipymodule.so* \
	  | ${CPIO} ${BINOWN}:${BINGRP} ${PYTHON_SITELIBDIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCDIR}/html
	@ ${MKDIR} ${DOCDIR}/tex
	@ ${INSTALL_DATA} ${BUILD_WRKSRC}/doc/omniORBpy.* ${DOCDIR}
	@ ${INSTALL_DATA} ${BUILD_WRKSRC}/doc/omniORBpy/* ${DOCDIR}/html
	@ ${INSTALL_DATA} ${BUILD_WRKSRC}/doc/tex/* ${DOCDIR}/tex
	@ ${MKDIR} ${EGDIR}
	@ cd ${BUILD_WRKSRC}/examples && find . \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${EGDIR}
.endif

.include <bsd.port.mk>
