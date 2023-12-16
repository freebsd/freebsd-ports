PORTNAME=	treesheets
DISTVERSION=	1.0.20231124
CATEGORIES=	deskutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Free form data organizer
WWW=		https://strlen.com/treesheets/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/ZLIB_LICENSE.txt

USES=		cmake compiler:c++17-lang desktop-file-utils gnome \
		shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	aardappel
GH_TAGNAME=	6985406227
USE_WX=		3.2

PORTSCOUT=	ignore:1 # upstream uses CI run ids as releases

PORTDATA=	images scripts
PORTDOCS=	docs readme.html
PORTEXAMPLES=	examples

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-tools

pre-build:
	@${REINPLACE_CMD} -e 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
