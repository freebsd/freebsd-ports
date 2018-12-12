# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	openspc
PORTVERSION=	0.3.1
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://membres.lycos.fr/pixels/ \
		LOCAL/ehaupt
DISTNAME=	OpenSPC-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line player for .spc and .zst files

ONLY_FOR_ARCHS=	i386	# contains x86 asm code
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf libtool
USE_GCC=	any
USE_LDCONFIG=	yes

PORTDOCS=	README
PLIST_FILES=	bin/OpenSPClite include/OpenSPC.h lib/libOpenSPC.a \
		lib/libOpenSPC.so lib/libOpenSPC.so.0 lib/libOpenSPC.so.0.3.1

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '1,/AUDIOFILE/d' ${WRKSRC}/acinclude.m4
	@${REINPLACE_CMD} '/AC_PROG_CC/{p;s/.*/AM_PROG_AS/;}' \
		${WRKSRC}/configure.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
