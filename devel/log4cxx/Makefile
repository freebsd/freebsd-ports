# New ports collection makefile for:	log4cxx
# Date created:		2005-01-12
# Whom:			Thaddeus Covert <tcovert@grimmy.sahuagin.net>
#
# $FreeBSD$

PORTNAME=	log4cxx
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	logging/${PORTNAME}/${PORTVERSION}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Log4cxx is a port to C++ of the Log4j project

LICENSE=	ASL

LIB_DEPENDS=	apr-1:${PORTSDIR}/devel/apr1

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
.endif

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:15:env autoconf:262:env libtool:22:env

MAKE_JOBS_UNSAFE=	yes

USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS) && defined(WITH_DOXYGEN)
PORTDOCS=	*
.endif

pre-configure:
	@${REINPLACE_CMD} -e '/^_LT_AC_SHELL_INIT/d' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.am
	@(cd ${WRKSRC} && ./autogen.sh)

post-install:
.if !defined(NOPORTDOCS) && defined(WITH_DOXYGEN)
	${MKDIR} ${DOCSDIR}
	for f in ${PORTDOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
