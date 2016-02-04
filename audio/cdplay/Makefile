# Created by: Antti Kaipila <anttik@iki.fi>
# $FreeBSD$

PORTNAME=	cdplay
PORTVERSION=	0.92
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	LOCAL/dannyboy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD-player with text-based user interface

USES=		ncurses
MAKE_ARGS=	CFLAGS="${CFLAGS} -c -ansi"	\
		LFLAGS="${LDFLAGS} -lncurses"   \
		BINPATH="${PREFIX}/bin/"	\
		MANPATH="${MANPREFIX}/man/man1/" \
		CC="${CC}"
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/cdplay \
		man/man1/cdplay.1.gz

post-patch:
	${REINPLACE_CMD}			\
		-e 's/^OPTIMISE=.*$$/OPTIMISE=/'\
		${WRKSRC}/Makefile

pre-patch:
	@${GUNZIP_CMD} ${WRKSRC}/cdplay.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdplay ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cdplay.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
