PORTNAME=	styx
DISTVERSION=	2.0.1
CATEGORIES=	devel
MASTER_SITES=	http://speculate.de/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scanner/parser generator
WWW=		http://www.speculate.de/

LICENSE=	GPLv3

USES=		autoreconf gmake iconv libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	EXAMPLES DOCS

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.mk>
