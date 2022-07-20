PORTNAME=	libhangul
PORTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	korean

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Library for Hangul processing

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/check.pc:devel/check

USES=		autoreconf iconv libtool pathfix pkgconfig

GH_ACCOUNT=	choehwanjin
GH_TAGNAME=	9fe2d4e
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
TEST_TARGET=	test
TEST_WRKSRC=	${WRKSRC}/test
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools

post-test:
	@${TEST_WRKSRC}/test

.include <bsd.port.mk>
