# Created by: Janni <jannisan@t-online.de>
# $FreeBSD$

PORTNAME=	Atlas
PORTVERSION=	0.6.3
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/${PORTNAME}-C%2B%2B%20%28protocol%20lib%29/${PORTVERSION}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-C++-${PORTVERSION:S/.r/rc/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	C++ reference implementation of the Atlas protocol

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USES=		libtool pathfix compiler:c++11-lib tar:bzip2
USE_LDCONFIG=	YES
MAKE_ARGS=	docdir=${DOCSDIR}
CONFIGURE_ARGS+=--program-transform-name=
CXXFLAGS_powerpc64=	-Wno-error=deprecated
CXXFLAGS_powerpc=	-Wno-error=deprecated
CXXFLAGS_powerpcspe=	-Wno-error=deprecated
CXXFLAGS_mips=	-Wno-error=deprecated
CXXFLAGS_mips64=	-Wno-error=deprecated
CXXFLAGS_sparc64=	-Wno-error=deprecated

post-patch:
	@${REINPLACE_CMD} -e 's|^static const bool debug_flag = false;$$||' \
		${WRKSRC}/Atlas/Message/DecoderBase.cpp \
		${WRKSRC}/Atlas/Codecs/Bach.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in README COPYING AUTHORS THANKS NEWS ChangeLog TODO HACKING ROADMAP
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
