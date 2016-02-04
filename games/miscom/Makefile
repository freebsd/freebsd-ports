# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	miscom
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atari "Missile Command" clone

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses

ALL_TARGET=	# empty

MAKE_ARGS=	CC="${CC}" DATADIR="${DATADIR}" \
		CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-DSOUNDSDIR='\"$(DATADIR)\"' -DSOUND_SUPPORT -DMORE_SOUNDBUF
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/miscom ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/miscom.6 ${STAGEDIR}${PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/miscom
	${INSTALL_DATA} ${WRKSRC}/sounds/* ${STAGEDIR}${PREFIX}/share/miscom
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/miscom
.for file in COPYING ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/share/doc/miscom
.endfor

.include <bsd.port.post.mk>
