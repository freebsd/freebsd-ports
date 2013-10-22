# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	epiar
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Space trading/exploring sim with RPG elements

LICENSE=	GPLv2 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE_CCbyNCSA3=${WRKSRC}/LICENSE.music
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libftgl.so:${PORTSDIR}/graphics/ftgl \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libphysfs.so:${PORTSDIR}/devel/physfs

USE_GITHUB=	yes
GH_ACCOUNT=	knowknowledge
GH_PROJECT=	Epiar
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	44046e3

USES=		gmake pkgconfig
USE_SDL=	image mixer sdl
USE_GL=		glu
USE_AUTOTOOLS=	aclocal autoheader automake autoconf
AUTOMAKE_ARGS=	--add-missing
ACLOCAL_ARGS=
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
