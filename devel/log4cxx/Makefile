# New ports collection makefile for:	log4cxx
# Date created:		2005-01-12
# Whom:			Thaddeus Covert <tcovert@grimmy.sahuagin.net>
#
# $FreeBSD$

PORTNAME=	log4cxx
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	logging/${PORTNAME}

MAINTAINER=	tcovert@sahuagin.net
COMMENT=	Log4cxx is a port to C++ of the Log4j project

.if !defined(NOPORTDOCS) && defined(WITH_DOXYGEN)
BUILD_DEPENDS+=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
.else
CONFIGURE_ARGS+=	--disable-doxygen
.endif

.if exists(${LOCALBASE}/lib/libboost_regex.so)
WITH_BOOST=	yes
.endif

.if defined(WITH_BOOST)
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/regex.hpp:${PORTSDIR}/devel/boost-libs
CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
.endif

USE_AUTOTOOLS=	automake:15 autoconf:262 libtool:22
AUTOMAKE_ARGS=	--add-missing
LIBTOOL_VARS=	--force --automake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-I${LOCALBASE}/lib

CONFIGURE_ARGS+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" CXXFLAGS="${CXXFLAGS}"
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS) && defined(WITH_DOXYGEN)
PORTDOCS=	*
.endif

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL})
	@${REINPLACE_CMD} -e '/^_LT_AC_SHELL_INIT/d' ${WRKSRC}/aclocal.m4

post-patch:
	@${REINPLACE_CMD} "s#\$$(DESTDIR)\$$(htmldir)#${DOCSDIR}/html#" ${WRKSRC}/docs/Makefile.am

post-install:
.if !defined(NOPORTDOCS) && defined(WITH_DOXYGEN)
	${MKDIR} ${DOCSDIR}
	for f in ${PORTDOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
