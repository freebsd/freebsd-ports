# Created by: Matthew Hunt <mph@freebsd.org>
# $FreeBSD$

PORTNAME=	intercal
PORTVERSION=	0.29
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The C-INTERCAL compiler, ick, and supporting libraries

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CFLAGS+=	-D_POSIX_SOURCE
DATADIR=	${PREFIX}/share/ick

MAN1=		ick.1 convickt.1
INFO=		ick

post-patch:
	@${REINPLACE_CMD} -e '/ICK_SPECIFIC_SUBDIR/s/-@PACKAGE_VERSION@// ' \
		${WRKSRC}/buildaux/Makefile.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
