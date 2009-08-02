# New ports collection makefile for:	openspc
# Date created:				10 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	openspc
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://membres.lycos.fr/pixels/ \
		CRITICAL
DISTNAME=	OpenSPC-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command line player for .spc and .zst files

ONLY_FOR_ARCHS=	i386	# contains x86 asm code
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
MAKE_JOBS_SAFE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/OpenSPClite include/OpenSPC.h lib/libOpenSPC.so \
		lib/libOpenSPC.so.3 lib/libOpenSPC.la lib/libOpenSPC.a

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
