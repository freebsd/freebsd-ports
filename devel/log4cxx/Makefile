# Created by:	Thaddeus Covert <tcovert@grimmy.sahuagin.net>
# $FreeBSD$

PORTNAME=	log4cxx
PORTVERSION=	0.10.0
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	logging/${PORTNAME}/${PORTVERSION}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Log4cxx is a port to C++ of the Log4j project

LICENSE=	AL2

LIB_DEPENDS=	apr-1:${PORTSDIR}/devel/apr1

OPTIONS_DEFINE=	BOOST DOCS DOXYGEN
OPTIONS_DEFAULT=

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
.else
CONFIGURE_ARGS+=	--disable-doxygen
.endif

.if ${PORT_OPTIONS:MBOOST}
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/regex.hpp:${PORTSDIR}/devel/boost-libs
.endif

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:env autoconf:env libtool:env

MAKE_JOBS_UNSAFE=	yes

USE_LDCONFIG=	yes

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
PORTDOCS=	*
.endif

pre-configure:
	@${REINPLACE_CMD} -e '/^_LT_AC_SHELL_INIT/d' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.am
	@(cd ${WRKSRC} && ./autogen.sh)
	@${REINPLACE_CMD} -e 's|GREP "\\-L"|GREP "conftest\\.$$objext"|g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
	${MKDIR} ${DOCSDIR}
	for f in ${PORTDOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
