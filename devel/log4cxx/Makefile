# Created by: Thaddeus Covert <tcovert@grimmy.sahuagin.net>
# $FreeBSD$

PORTNAME=	log4cxx
PORTVERSION=	0.10.0
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	APACHE/logging/${PORTNAME}/${PORTVERSION}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ port of the Log4j project

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libapr-1.so:devel/apr1

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:env autoconf:env
USES=		pathfix libtool
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	BOOST DOXYGEN

BOOST_BUILD_DEPENDS=	${LOCALBASE}/include/boost/regex.hpp:devel/boost-libs

DOXYGEN_CONFIGURE_OFF=	--disable-doxygen
DOXYGEN_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:devel/doxygen

post-configure:
	@${REINPLACE_CMD} -e 's|-dpR|-pr|' \
		-e '/^htmldest/ s|$$(pkgdatadir)|${DOCSDIR}|' \
		${WRKSRC}/src/site/doxy/Makefile

post-install-DOXYGEN-on:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${DOCSDIR:S|${PREFIX}/||} ! -type d >> ${TMPPLIST}

.include <bsd.port.mk>
