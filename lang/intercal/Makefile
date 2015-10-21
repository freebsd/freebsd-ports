# Created by: Matthew Hunt <mph@FreeBSD.org>
# $FreeBSD$

PORTNAME=	intercal
PORTVERSION=	0.30
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	C-INTERCAL compiler, ick, and supporting libraries

GNU_CONFIGURE=	yes
USES=		gmake
CFLAGS+=	-D_POSIX_SOURCE
DATADIR=	${PREFIX}/share/ick

INFO=		ick

post-patch:
	@${REINPLACE_CMD} -e '/ICK_SPECIFIC_SUBDIR/s/-@PACKAGE_VERSION@// ' \
		${WRKSRC}/buildaux/Makefile.in

.include <bsd.port.mk>
