# Created by: Janni <jannisan@t-online.de>
# $FreeBSD$

PORTNAME=	Atlas
PORTVERSION=	0.6.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/${PORTNAME}-C%2B%2B%20%28protocol%20lib%29/${PORTVERSION}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-C++-${PORTVERSION:S/.r/rc/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	C++ reference implementation of the Atlas protocol

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix compiler:c++11-lib tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	docdir=${DOCSDIR}

CXXFLAGS_powerpc64=	-Wno-error=deprecated
CXXFLAGS_powerpc=	-Wno-error=deprecated
CXXFLAGS_powerpcspe=	-Wno-error=deprecated
CXXFLAGS_mips=		-Wno-error=deprecated
CXXFLAGS_mips64=	-Wno-error=deprecated
CXXFLAGS_sparc64=	-Wno-error=deprecated

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^static const bool debug_flag = false;$$||' \
		${WRKSRC}/Atlas/Message/DecoderBase.cpp \
		${WRKSRC}/Atlas/Codecs/Bach.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in README AUTHORS THANKS NEWS ChangeLog TODO HACKING ROADMAP
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
