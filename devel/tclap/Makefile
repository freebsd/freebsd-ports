PORTNAME=	tclap
DISTVERSION=	1.4.0-rc1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Verbose replacement for getopt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing python:test shebangfix tar:bz2

SHEBANG_GLOB=	*.py

CMAKE_TESTING_ON=	FREEBSD_TESTS # tests are broken: https://sourceforge.net/p/tclap/bugs/36/ (can't find directories)

NO_ARCH=	yes # builds tests unconditionally https://sourceforge.net/p/tclap/bugs/35/

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
