# Created by: Jesse Smith <jessefrgsmith@yahoo.ca>
# $FreeBSD$

PORTNAME=	atanks
PORTVERSION=	5.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	2D tank game with large, cartoonish weapons

LICENSE=	GPLv2

LIB_DEPENDS=	liballeg.so:devel/allegro

USES=		gmake
MAKE_ARGS+=	PREFIX=${PREFIX}/
MAKE_ARGS+=	CC=${CC} CPP=${CXX} LD=${LD}
PATCH_DEBUG=	1

PORTDOCS=	Changelog README README_ru.txt credits.txt
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/^LDFLAGS =/s/$$/ -pthread/' ${WRKSRC}/src/Makefile.bsd
	@${REINPLACE_CMD} -e \
		's/int Filter_File( struct dirent/int Filter_File( const struct dirent/' \
		${WRKSRC}/src/files.cpp

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${LN} -sf ${DOCSDIR}/credits.txt ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
