PORTNAME=	openspc
PORTVERSION=	0.3.1
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	http://membres.lycos.fr/pixels/ \
		LOCAL/ehaupt
DISTNAME=	OpenSPC-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line player for .spc and .zst files
WWW=		http://membres.lycos.fr/pixels/OpenSPC.html

DEPRECATED=	Unmaintained upstream. Use audio/libgme or audio/ocp instead.
EXPIRATION_DATE=	2024-12-05

ONLY_FOR_ARCHS=	i386 # contains x86 asm code

USES=		autoreconf libtool
USE_GCC=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/OpenSPClite \
		include/OpenSPC.h \
		lib/libOpenSPC.a \
		lib/libOpenSPC.so \
		lib/libOpenSPC.so.0 \
		lib/libOpenSPC.so.0.3.1
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '1,/AUDIOFILE/d' ${WRKSRC}/acinclude.m4
	@${REINPLACE_CMD} '/AC_PROG_CC/{p;s/.*/AM_PROG_AS/;}' \
		${WRKSRC}/configure.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
