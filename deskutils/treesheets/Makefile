PORTNAME=	treesheets
DISTVERSION=	1.0.20220909
PORTREVISION=	1
CATEGORIES=	deskutils

PATCH_SITES=	https://github.com/aardappel/treesheets/commit/
PATCHFILES=	927f542abcca8000f8019dda6215e54938c8e457.patch:-p1 # https://github.com/aardappel/treesheets/issues/260

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Free form data organizer
WWW=		https://strlen.com/treesheets/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/ZLIB_LICENSE.txt

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
