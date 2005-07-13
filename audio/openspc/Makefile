# New ports collection makefile for:	openspc
# Date created:				10 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	openspc
PORTVERSION=	0.3.1
CATEGORIES=	audio
MASTER_SITES=	http://membres.lycos.fr/pixels/
DISTNAME=	OpenSPC-${PORTVERSION}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A command line player for .spc and .zst files

ONLY_FOR_ARCHS=	i386	# contains x86 asm code
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13

PORTDOCS=	README
PLIST_FILES=	bin/OpenSPClite include/OpenSPC.h lib/libOpenSPC.so lib/libOpenSPC.so.3 \
		lib/libOpenSPC.la lib/libOpenSPC.a

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
