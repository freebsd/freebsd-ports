PORTNAME=	timewarrior
PORTVERSION=	1.4.3
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Track time from the command line

LICENSE=	MIT

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor

USES=		cmake:insource compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	GothenburgBitFactory
GH_TUPLE=	GothenburgBitFactory:libshared:c1760be:libshared/src/libshared
CMAKE_ARGS+=	-DTIMEW_DOCDIR=${DOCSDIR}

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/man/man1/CMakeFiles ${STAGEDIR}${PREFIX}/man/man7/CMakeFiles

.include <bsd.port.mk>
