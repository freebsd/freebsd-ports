PORTNAME=	rampler
DISTVERSION=	2.0.0
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Standalone module for sampling genomic sequences

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bioparser>0:biology/bioparser \
		${LOCALBASE}/include/biosoup/nucleic_acid.hpp:biology/biosoup

USES=		cmake compiler:c++11-lang localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rvaser

LDFLAGS+=	-lz

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
