PORTNAME=	mashmap
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.6
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast approximate aligner for long DNA sequences
WWW=		https://github.com/marbl/MashMap

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		cmake compiler:c++17-lang localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	marbl
GH_PROJECT=	MashMap

PLIST_FILES=	bin/mashmap \
		bin/mashmap-align

.include <bsd.port.mk>
