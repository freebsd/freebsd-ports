PORTNAME=	libEMF
DISTVERSION=	1.0.13
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	libemf-${DISTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Enhanced Metafile Library
WWW=		http://libemf.sourceforge.net/

LICENSE=	LGPL21

USES=		compiler:c++14-lang cpe libtool
CPE_VENDOR=	${PORTNAME:tl}_project
# libEMF 1.10.13 does not work with C++17 which is the default since
# clang 16. This can be removed once that port starts working with C++17 and
# has its own USE_CXXSTD removed.
# See also: https://sourceforge.net/p/libemf/bugs/5/
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
