PORTNAME=	padring
DISTVERSION=	g20210731
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Padring generator for ASICs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	donn
GH_TAGNAME=	b2a64ab

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.mk>
