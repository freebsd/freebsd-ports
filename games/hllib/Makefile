PORTNAME=	hllib
PORTVERSION=	2.4.6
CATEGORIES=	games devel
MASTER_SITES=	https://github.com/osen/distfiles/raw/main/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	kpedersen@disroot.org
COMMENT=	Library to work with various Half-Life file formats

LICENSE=	LGPL21

USES=		dos2unix zip
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/HLLib
CFLAGS+=	-fpic -DUSE_ZLIB

PATCH_WRKSRC=	${WRKDIR}

PLIST_FILES=	include/hl.h lib/libhl.so.${PORTVERSION} \
		lib/libhl.so.2 lib/libhl.so

MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}"

post-patch:
# Allow propagating of CXX, CXXFLAGS, and PREFIX; fix Linuxism and symlinks
	@${REINPLACE_CMD} -E 's,^([CP][^=]*)=,\1?=, ; s,-g root,,g ; \
		s,-o root,,g ; s,s \$$\(PREFIX\)/lib/,s ,' ${WRKSRC}/Makefile
# Fix library version
	@${REINPLACE_CMD} -e 's/2\.3\.0/2\.4\.6/' ${WRKSRC}/Makefile
# Add missing -lz
	@${REINPLACE_CMD} -e '/$$(LDFLAGS)/s,$$, -lz,' ${WRKSRC}/Makefile

.include <bsd.port.mk>
