PORTNAME=	Atlas
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/OldFiles
DISTNAME=	${PORTNAME}-C++-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	C++ reference implementation of the Atlas protocol
WWW=		https://www.worldforge.org/index.php/components/atlas-cpp/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix tar:bzip2
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

MAKE_ARGS=	docdir=${DOCSDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
