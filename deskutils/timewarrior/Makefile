PORTNAME=	timewarrior
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
CATEGORIES=	deskutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Track time from the command line
WWW=		https://timewarrior.net/

LICENSE=	MIT

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor

USES=		cmake:insource compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	GothenburgBitFactory
GH_TUPLE=	GothenburgBitFactory:libshared:7604fd2:libshared/src/libshared

CMAKE_ARGS+=	-DTIMEW_DOCDIR=${DOCSDIR}

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/man/man1/CMakeFiles ${STAGEDIR}${PREFIX}/share/man/man7/CMakeFiles

.include <bsd.port.mk>
