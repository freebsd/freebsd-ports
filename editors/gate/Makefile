# Created by: James Howard
# $FreeBSD$

PORTNAME=	gate
PORTVERSION=	2.06
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.unixpapa.com/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and unobtrusive line-oriented text editor

BUILD_DEPENDS=	aspell:textproc/aspell
RUN_DEPENDS=	aspell:textproc/aspell

USES=		ncurses
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-aspell=${LOCALBASE}/bin/aspell
ALL_TARGET=	gate gate.1

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${res_datadir}|${DATADIR}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^char \*malloc();||g' ${WRKSRC}/term.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gate ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gate.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gate.help ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
