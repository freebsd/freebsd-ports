PORTNAME=	log4cpp
PORTVERSION=	1.1.4
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}.x%20%28new%29/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of C++ classes for flexible logging
WWW=		http://log4cpp.sourceforge.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-html-docs
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENABLE=	doxygen

post-patch:
	@${RM} ${WRKSRC}/doc/Doxyfile.in.orig ${WRKSRC}/doc/Makefile.in.orig

.include <bsd.port.mk>
