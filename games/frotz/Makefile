# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	frotz
PORTVERSION=	2.44
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Infocom games interpreter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	DavidGriffith

USES=		gmake ncurses

MAKE_ARGS=	-e CURSES="${LDFLAGS} -lncurses"
MAKE_ENV=	OPTS="${CFLAGS}" CONFIG_DIR="${PREFIX}/etc"

PLIST_FILES=	bin/frotz \
		man/man6/frotz.6.gz

PORTDOCS=	AUTHORS BUGS ChangeLog HOW_TO_PLAY README
PORTEXAMPLES=	frotz.conf-big frotz.conf-small

OPTIONS_DEFINE=		DOCS EXAMPLES DUMB OSS
OPTIONS_DEFAULT=	OSS
DUMB_DESC=		Install dfrotz (dumb frotz)

OSS_MAKE_ENV=		SOUND_DEFS='-DOSS_SOUND -DSOUND_DEV=\"/dev/dsp\"'
DUMB_PLIST_FILES=	bin/dfrotz \
			man/man6/dfrotz.6.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDUMB}
PORTDOCS+=	DUMB
.endif

.if ${PORT_OPTIONS:MOSS}
pre-build:
	cd ${WRKSRC} && ${DO_MAKE_BUILD} soundcard.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/
.if ${PORT_OPTIONS:MDUMB}
	${INSTALL_PROGRAM} ${WRKSRC}/d${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/d${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
