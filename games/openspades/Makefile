# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openspades
PORTVERSION=	0.0.12
DISTVERSIONPREFIX=	v
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://yvt.jp/files/programs/osppaks/:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} DevPaks27.zip:data

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Compatible client of Ace of Spades

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	convert:graphics/ImageMagick6 # for building icons
LIB_DEPENDS=	libcurl.so:ftp/curl

NOT_FOR_ARCHS=		aarch64 powerpc64
NOT_FOR_ARCHS_REASON=	fails to compile: uses x86 assembly

USE_GITHUB=	yes
GH_ACCOUNT=	yvt

USES=		cmake compiler:c++11-lib desktop-file-utils
CMAKE_ARGS=	-DOPENSPADES_RESOURCES=OFF \
		-DOPENSPADES_INSTALL_MAN="man/man6" \
		-DOPENSPADES_INSTALL_BINARY="bin" \
		-DOPENSPADES_INSTALL_RESOURCES="${DATADIR_REL}"
USE_SDL=	sdl2 image2
USE_GL=		gl glew
INSTALLS_ICONS=	yes

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MKDIR} ${WRKSRC}/Resources/DevPak
	@${MV} ${WRKDIR}/*.pak ${WRKSRC}/Resources/DevPak/

post-patch:
	@${REINPLACE_CMD} -e 's|Xext|${LOCALBASE}/lib/lib&.so|' ${WRKSRC}/Sources/CMakeLists.txt

.include <bsd.port.mk>
