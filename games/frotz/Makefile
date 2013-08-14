# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	frotz
PORTVERSION=	2.43d
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.43/ \
		http://www.ifarchive.org/if-archive/infocom/interpreters/frotz/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Infocom games interpreter

LICENSE=	GPLv2 # (or later)

MAKE_ARGS=	CC="${CC}" OPTS="${CFLAGS}" PREFIX="${PREFIX}" \
		CONFIG_DIR="${PREFIX}/etc" SOUND_DEFS="-DOSS_SOUND" \
		SOUND_DEV="/dev/dsp" INCL="" LIB=""

MAN6=		frotz.6 dfrotz.6
PORTDOCS=	AUTHORS BUGS ChangeLog DUMB HOW_TO_PLAY README
PORTEXAMPLES=	frotz.conf-big frotz.conf-small
PLIST_FILES=	bin/frotz

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.for m in ${MAN6}
	${INSTALL_MAN} ${WRKSRC}/doc/${m} ${MAN6PREFIX}/man/man6
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for ex in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${ex} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
