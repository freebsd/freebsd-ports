# New ports collection makefile for:	py-omniorb
# Date created:		14 November 2000
# Whom:			Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	omniorb
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	omniORBpy-${PORTVERSION}

MAINTAINER=	sem@ciam.ru
COMMENT=	Python bindings for omniORB4, a CORBA 2.6 ORB

LIB_DEPENDS=	omniORB4.0:${PORTSDIR}/devel/omniORB
RUN_DEPENDS=	omniidl:${PORTSDIR}/devel/omniORB
# parts of omniORB4 source tree is required to build omniORBpy;
# see also the "post-extract" target below.
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/omniORB:patch

CONFLICTS=	py*-orbit-2*

CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
OMNIORB_WRKSRC!=	cd ${.CURDIR}/../omniORB && ${MAKE} -V WRKSRC

USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV+=	CC=${CC} CFLAGS="${CFLAGS}" CXX=${CXX} CXXFLAGS="${CXXFLAGS}" \
		CPP=${CPP} PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--with-openssl=/usr --with-omniorb=${LOCALBASE}

CPIO=		cpio --quiet -pdum

MODULEDIRS=	CosNaming CosNaming__POA omniORB
DOCSDIR=	${PREFIX}/share/doc/omniORBpy
EXAMPLESDIR=	${PREFIX}/share/examples/omniORBpy

pre-configure:
	@ ${MKDIR} ${CONFIGURE_WRKSRC}
	@ cd ${OMNIORB_WRKSRC} && ${FIND} idl | ${CPIO} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -Ee 's#-pthread|-lc_r#${PTHREAD_LIBS}#' \
		${WRKSRC}/mk/beforeauto.mk.in

pre-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}/html
	@ ${MKDIR} ${DOCSDIR}/tex
	@ ${INSTALL_DATA} ${WRKSRC}/doc/omniORBpy.* ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/omniORBpy/* ${DOCSDIR}/html
	@ ${INSTALL_DATA} ${WRKSRC}/doc/tex/* ${DOCSDIR}/tex
	@ ${MKDIR} ${EXAMPLESDIR}
	@ cd ${WRKSRC}/examples && ${FIND} . \
	  | ${CPIO} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
