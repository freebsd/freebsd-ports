# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	openspc
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://membres.lycos.fr/pixels/ \
		CRITICAL
DISTNAME=	OpenSPC-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line player for .spc and .zst files

ONLY_FOR_ARCHS=	i386	# contains x86 asm code
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GCC=	any

PORTDOCS=	README
PLIST_FILES=	bin/OpenSPClite include/OpenSPC.h lib/libOpenSPC.so \
		lib/libOpenSPC.so.3 lib/libOpenSPC.la lib/libOpenSPC.a

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
