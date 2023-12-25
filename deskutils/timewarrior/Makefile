PORTNAME=	timewarrior
PORTVERSION=	1.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Track time from the command line
WWW=		https://timewarrior.net/

LICENSE=	MIT

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor

USES=		cmake:insource compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	GothenburgBitFactory
GH_TUPLE=	GothenburgBitFactory:libshared:47c3262:libshared/src/libshared

CMAKE_ARGS+=	-DTIMEW_DOCDIR=${DOCSDIR}

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/man/man1/CMakeFiles ${STAGEDIR}${PREFIX}/man/man7/CMakeFiles

.include <bsd.port.mk>
