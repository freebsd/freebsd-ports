# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	tanglet
PORTVERSION=	1.2.2
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@FreeBSD.org

COMMENT=	Single player word finding game based on Boggle

LICENSE=	GPLv3

USE_BZIP2=	yes
USES=		desktop-file-utils qmake
USE_QT4=	moc_build rcc_build gui iconengines_run imageformats_run
LDFLAGS+=	-lz
INSTALLS_ICONS=	yes

PORTDOCS=	CREDITS ChangeLog NEWS

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -i '' -e '/PKGCONFIG += zlib/d' \
		${WRKSRC}/tanglet.pro

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		    ${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
