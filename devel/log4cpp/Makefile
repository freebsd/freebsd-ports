# Created by: ijliao@FreeBSD.org
# $FreeBSD$

PORTNAME=	log4cpp
PORTVERSION=	1.1.3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}.x%20%28new%29/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of C++ classes for flexible logging

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=		fails to compile: Appender.cpp: extra ';'
BROKEN_mips64=		fails to compile: Appender.cpp: extra ';'
BROKEN_powerpc64=	fails to compile: Appender.cpp: extra ';'

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-html-docs
REINPLACE_ARGS=	-i ""
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENABLE=	doxygen

post-patch:
	@${REINPLACE_CMD} -e \
		's|^MAX_|#MAX_|' \
		${WRKSRC}/doc/Doxyfile.in
	@${REINPLACE_CMD} -e \
		's|$$(prefix)/doc/.*|@docdir@| ; \
		 s|\([[:blank:]]\)\($$(man3dir)\)|\1$$(DESTDIR)\2| ; \
		 s|\([[:blank:]]\)\($$(docdir)\)|\1$$(DESTDIR)\2|' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
