PORTNAME=	vms-empire
DISTVERSION=	1.18
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Simulation of a full-scale war between two emperors
WWW=		http://www.catb.org/~esr/vms-empire/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ncurses
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"

PLIST_FILES=	${DESKTOPDIR}/${PORTNAME}.desktop \
		bin/${PORTNAME} \
		share/appdata/${PORTNAME}.xml \
		share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		share/man/man6/${PORTNAME}.6.gz

PORTDOCS=	AUTHORS BUGS HACKING NEWS README
OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
