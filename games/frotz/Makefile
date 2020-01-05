# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	frotz
PORTVERSION=	2.50
CATEGORIES=	games

MAINTAINER=	dave@661.org
COMMENT=	Infocom Z-machine games interpreter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITLAB=	yes
GL_ACCOUNT=	DavidGriffith
GL_COMMIT=	9867a1f14da1e9c0707492d2ac74d1e8ffdd3a64

USES=		gmake ncurses

MAKE_ENV=	OPTS="${CFLAGS}" CONFIG_DIR="${PREFIX}/etc"

ALL_TARGET=	nosound dumb
INSTALL_TARGET=	frotz

PLIST_FILES=	bin/frotz \
		man/man6/frotz.6.gz

PORTDOCS=	AUTHORS ChangeLog HOW_TO_PLAY README
PORTEXAMPLES=	frotz.conf-big frotz.conf-small

OPTIONS_DEFINE=		DOCS EXAMPLES DUMB
DUMB_DESC=		Install dfrotz (dumb frotz)

DUMB_PLIST_FILES=	bin/dfrotz \
			man/man6/dfrotz.6.gz
DUMB_PORTDOCS=	DUMB

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-install-DUMB-on:
	${INSTALL_PROGRAM} ${WRKSRC}/d${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/d${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
