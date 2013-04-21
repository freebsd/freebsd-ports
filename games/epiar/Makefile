# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	epiar
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://epiar.net/files/epiar/releases/0.5/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Space trading/exploring sim with RPG elements

LICENSE=	GPLv2 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE_CCbyNCSA3=${WRKSRC}/LICENSE.music
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		ftgl:${PORTSDIR}/graphics/ftgl \
		xml2:${PORTSDIR}/textproc/libxml2 \
		physfs:${PORTSDIR}/devel/physfs

USE_BZIP2=	yes
USE_SDL=	image mixer sdl
USE_GL=		glu
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal
USE_GMAKE=	yes
USE_PKGCONFIG=	build
MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS ChangeLog README

pre-configure:
	@${REINPLACE_CMD} -e 's|9.22|2.4|' ${WRKSRC}/configure.in
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
