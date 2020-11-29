# Created by: Matthew Hunt <mph@FreeBSD.org>
# $FreeBSD$

PORTNAME=	intercal
PORTVERSION=	0.30
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C-INTERCAL compiler, ick, and supporting libraries

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes
CFLAGS+=	-D_POSIX_SOURCE
DATADIR=	${PREFIX}/share/ick

INFO=		ick

post-patch:
	@${REINPLACE_CMD} -e '/ICK_SPECIFIC_SUBDIR/s/-@PACKAGE_VERSION@// ' \
		${WRKSRC}/buildaux/Makefile.in

.include <bsd.port.mk>
