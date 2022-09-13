PORTNAME=	treesheets
DISTVERSION=	1.0.20220909
CATEGORIES=	deskutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Free form data organizer
WWW=		https://strlen.com/treesheets/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/ZLIB_LICENSE.txt

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON_i386=	unsupported platform: https://github.com/aardappel/treesheets/issues/260

USES=		cmake compiler:c++17-lang desktop-file-utils gettext gnome

USE_GITHUB=	yes
GH_ACCOUNT=	aardappel
GH_TAGNAME=	3025803779
USE_WX=		3.1

PORTDATA=	images scripts
PORTDOCS=	docs readme.html
PORTEXAMPLES=	examples

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
