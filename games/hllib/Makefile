# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hllib
PORTVERSION=	2.4.3
CATEGORIES=	games devel
MASTER_SITES=	http://nemesis.thewavelength.net/files/files/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to work with various Half-Life file formats

LICENSE=	LGPL21

USE_ZIP=	yes
USE_DOS2UNIX=	Makefile			# required by make(1)
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/HLLib
CFLAGS+=	-fpic -DUSE_ZLIB

HLLIB_VERS=	2.3.0
PLIST_FILES=	include/hl.h lib/libhl.so.${HLLIB_VERS} \
		lib/libhl.so.2 lib/libhl.so

post-patch:
# Allow propagating of CXX, CXXFLAGS, and PREFIX; fix Linuxism and symlinks
	@${REINPLACE_CMD} -E 's,^([CP][^=]*)=,\1?=, ; s,g root,g wheel, ; \
		s,s \$$\(PREFIX\)/lib/,s ,' ${WRKSRC}/Makefile
# Add forgotten file to the source list so it would be picked up by linker
	@${REINPLACE_CMD} -e 's,ProcStream\.cpp,& SGAFile.cpp,' \
		${WRKSRC}/Makefile
# Remove two lines of code that offend C++ compiler
	@${REINPLACE_CMD} -e '/friend CSGADirectory/d' ${WRKSRC}/SGAFile.h
# Add missing -lz
	@${REINPLACE_CMD} -e '/$$(LDFLAGS)/s,$$, -lz,' ${WRKSRC}/Makefile

.include <bsd.port.mk>
