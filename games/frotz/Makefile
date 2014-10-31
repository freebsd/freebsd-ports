# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	frotz
PORTVERSION=	2.43d
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:S/d//}/ \
		http://www.ifarchive.org/if-archive/infocom/interpreters/frotz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Infocom games interpreter

LICENSE=	GPLv2

MAKE_ARGS=	CC="${CC}" OPTS="${CFLAGS}" PREFIX="${PREFIX}" \
		CONFIG_DIR="${PREFIX}/etc" SOUND_DEFS="-DOSS_SOUND" \
		SOUND_DEV="/dev/dsp" INCL="" LIB=""

PLIST_FILES=	bin/frotz \
		man/man6/dfrotz.6.gz \
		man/man6/frotz.6.gz

PORTDOCS=	AUTHORS BUGS ChangeLog DUMB HOW_TO_PLAY README
PORTEXAMPLES=	frotz.conf-big frotz.conf-small

OPTIONS_DEFINE= DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	${INSTALL_MAN} ${WRKSRC}/doc/*.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/doc/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
