# New ports collection makefile for:	HLLib
# Date created:				22 Oct 2007
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hllib
PORTVERSION=	2.0.6
CATEGORIES=	games devel
MASTER_SITES=	http://nemesis.thewavelength.net/files/files/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}208

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library to work with various Half-Life file formats

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
