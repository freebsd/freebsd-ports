# New ports collection makefile for:	py-omniorb
# Date created:		14 November 2000
# Whom:			Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	omniorb
PORTVERSION=	2.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	omniORBpy-${PORTVERSION}

MAINTAINER=	ak03@gte.com

LIB_DEPENDS=	omniORB4.0:${PORTSDIR}/devel/omniORB
RUN_DEPENDS=	omniidl:${PORTSDIR}/devel/omniORB
# parts of omniORB4 source tree is required to build omniORBpy;
# see also the "post-extract" target below.
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/omniORB:patch

CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
OMNIORB_WRKSRC!=	cd $(.CURDIR)/../omniORB && ${MAKE} -V WRKSRC

USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile

CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV+= CC=${CC} CFLAGS="${CFLAGS}" CXX=${CXX} CXXFLAGS="${CXXFLAGS}" \
		CPP=${CPP} PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--with-openssl=/usr --with-omniorb=$(LOCALBASE)

CPIO=		cpio --quiet -pdum

MODULEDIRS=	CosNaming CosNaming__POA omniORB
DOCDIR=		${PREFIX}/share/doc/omniORBpy
EGDIR=		${PREFIX}/share/examples/omniORBpy

post-extract:
	@ ${MKDIR} ${CONFIGURE_WRKSRC}
	@ cd ${OMNIORB_WRKSRC} && find idl | ${CPIO} ${WRKSRC}

pre-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCDIR}/html
	@ ${MKDIR} ${DOCDIR}/tex
	@ ${INSTALL_DATA} ${WRKSRC}/doc/omniORBpy.* ${DOCDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/omniORBpy/* ${DOCDIR}/html
	@ ${INSTALL_DATA} ${WRKSRC}/doc/tex/* ${DOCDIR}/tex
	@ ${MKDIR} ${EGDIR}
	@ cd ${WRKSRC}/examples && find . \
	  | ${CPIO} -R ${SHAREOWN}:${SHAREGRP} ${EGDIR}
.endif

.include <bsd.port.mk>
