# Created by: Antti Kaipila <anttik@iki.fi>
# $FreeBSD$

PORTNAME=	cdplay
PORTVERSION=	0.92
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	LOCAL/dannyboy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD-player with text-based user interface

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		ncurses
MAKE_ARGS=	CFLAGS="${CFLAGS} -c -ansi"	\
		LFLAGS="${LDFLAGS} -lncurses"   \
		BINPATH="${PREFIX}/bin/"	\
		MANPATH="${MANPREFIX}/man/man1/" \
		CC="${CC}"
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

PLIST_FILES=	bin/cdplay \
		share/man/man1/cdplay.1.gz

post-patch:
	${REINPLACE_CMD}			\
		-e 's/^OPTIMISE=.*$$/OPTIMISE=/'\
		${WRKSRC}/Makefile

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/cdplay.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdplay ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cdplay.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
