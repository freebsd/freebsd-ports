PORTNAME=	log4cpp
PORTVERSION=	1.1.5
CATEGORIES=	devel
MASTER_SITES=	SF/log4cpp/log4cpp-1.1.x%20%28new%29/log4cpp-1.1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library of C++ classes for flexible logging
WWW=		https://log4cpp.sourceforge.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang gmake libtool pathfix

CONFIGURE_ARGS=	--disable-dot --disable-html-docs --disable-latex-docs
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/log4cpp

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENABLE=	doxygen

post-patch:
	@${RM} ${WRKSRC}/doc/Doxyfile.in.orig ${WRKSRC}/doc/Makefile.in.orig

.include <bsd.port.mk>
