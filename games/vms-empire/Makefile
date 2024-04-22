PORTNAME=	vms-empire
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulation of a full-scale war between two emperors
WWW=		http://www.catb.org/~esr/vms-empire/

LICENSE=	GPLv2

USES=		ncurses
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"
PORTDOCS=	AUTHORS BUGS HACKING NEWS README
OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man6/${PORTNAME}.6.gz \
		share/appdata/${PORTNAME}.xml \
		${DESKTOPDIR}/${PORTNAME}.desktop \
		share/icons/hicolor/48x48/apps/${PORTNAME}.png

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS|CFLAGS?|; \
	s|/usr/bin|${PREFIX}/bin|; \
	s|/usr/share/|${PREFIX}/share/|; \
	s|/usr/local/share/man|${PREFIX}/share/man|' \
	${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
