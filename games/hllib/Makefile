# New ports collection makefile for:	HLLib
# Date created:				22 Oct 2007
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hllib
PORTVERSION=	2.3.0
CATEGORIES=	games devel
MASTER_SITES=	http://nemesis.thewavelength.net/files/files/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library to work with various Half-Life file formats

LICENSE=	LGPL21

USE_ZIP=	yes
USE_DOS2UNIX=	Makefile
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/HLLib
CFLAGS+=	-fpic

PLIST_FILES=	include/hl.h lib/libhl.so.${PORTVERSION} \
		lib/libhl.so.2 lib/libhl.so

post-extract:
# Allow propagating of CXX, CXXFLAGS, and PREFIX; fix Linuxism and symlinks
	@${REINPLACE_CMD} -E 's,^([CP][^=]*)=,\1?=, ; s,g root,g wheel, ; \
		s,s \$$\(PREFIX\)/lib/,s ,' ${WRKSRC}/Makefile

.include <bsd.port.mk>
