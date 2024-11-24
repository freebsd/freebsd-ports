PORTNAME=	atf
PORTVERSION=	0.21
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C, C++ and shell libraries to write ATF-compliant test programs
WWW=		https://github.com/freebsd/atf

LICENSE=	BSD3CLAUSE

USES=		autoreconf libtool pathfix
USE_CXXSTD=	gnu++11
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_TAGNAME=	511d921
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_DEFAULT=TEST
OPTIONS_SUB=	yes

DOCS_MAKE_ARGS_OFF=	doc_DATA=

post-install-TEST-off:
	@${RM} -r ${STAGEDIR}${PREFIX}/tests

.include <bsd.port.mk>
