PORTNAME=	miscom
PORTVERSION=	1.0
PORTREVISION=	1
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
		share/man/man6/${PORTNAME}.6.gz
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-DSOUNDSDIR='\"${DATADIR}\"' -DSOUND_SUPPORT -DMORE_SOUNDBUF
.endif

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/miscom ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/miscom.6 ${STAGEDIR}${PREFIX}/share/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sounds/* ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in COPYING ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
