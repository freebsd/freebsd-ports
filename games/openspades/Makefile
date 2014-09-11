# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openspades
PORTVERSION=	0.0.12
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://yvt.jp/files/programs/osppaks/:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} DevPaks27.zip:data

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Compatible client of Ace of Spades

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick # for building icons
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libGLEW.so:${PORTSDIR}/graphics/glew

USE_GITHUB=	yes
GH_ACCOUNT=	yvt
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	6a310d8

USES=		compiler:c++11-lib cmake desktop-file-utils
CMAKE_ARGS=	-DOPENSPADES_RESOURCES=OFF \
		-DOPENSPADES_INSTALL_MAN="man/man6" \
		-DOPENSPADES_INSTALL_BINARY="bin" \
		-DOPENSPADES_INSTALL_RESOURCES="${DATADIR_REL}"
USE_SDL=	sdl2 image2
USE_GL=		gl
INSTALLS_ICONS=	yes

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
BROKEN=		doesn't build on pre-10.x
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/Resources/DevPak
	@${MV} ${WRKDIR}/*.pak ${WRKSRC}/Resources/DevPak/

post-patch:
	@${REINPLACE_CMD} -e 's|Xext|${LOCALBASE}/lib/lib&.so|' ${WRKSRC}/Sources/CMakeLists.txt

.include <bsd.port.post.mk>
