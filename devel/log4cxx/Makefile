# Created by: Thaddeus Covert <tcovert@grimmy.sahuagin.net>
# $FreeBSD$

PORTNAME=	log4cxx
PORTVERSION=	0.10.0
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	logging/${PORTNAME}/${PORTVERSION}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Log4cxx is a port to C++ of the Log4j project

LICENSE=	AL2

LIB_DEPENDS=	apr-1:${PORTSDIR}/devel/apr1

OPTIONS_DEFINE=	BOOST DOCS DOXYGEN

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

USES=	pathfix

post-install:
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
	${MKDIR} ${DOCSDIR}
	for f in ${PORTDOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
