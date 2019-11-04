# Created by: Matthew Hunt <mph@FreeBSD.org>
# $FreeBSD$

PORTNAME=	intercal
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C-INTERCAL compiler, ick, and supporting libraries

BROKEN_aarch64=	ld: error: lexer.c:(function yylex: .text+0x10CC): improper alignment for relocation R_AARCH64_LDST32_ABS_LO12_NC: 0x28001B is not aligned to 4 bytes

GNU_CONFIGURE=	yes
USES=		gmake
CFLAGS+=	-D_POSIX_SOURCE
DATADIR=	${PREFIX}/share/ick

INFO=		ick

post-patch:
	@${REINPLACE_CMD} -e '/ICK_SPECIFIC_SUBDIR/s/-@PACKAGE_VERSION@// ' \
		${WRKSRC}/buildaux/Makefile.in

.include <bsd.port.mk>
