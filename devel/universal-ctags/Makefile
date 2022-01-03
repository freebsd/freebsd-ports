# Created by: Derek Schrock <dereks@lifeofadishwasher.com>

PORTNAME=	universal-ctags
PORTVERSION=	p5.9.20220102.0
CATEGORIES=	devel

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Fork of Exuberant Ctags to generate index/tag files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake pkgconfig
USE_GITHUB=	yes
GH_PROJECT=	ctags

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=u

TEST_TARGET=	check

OPTIONS_DEFINE=		DEBUG ICONV JSON LIBXML2 MANPAGES PCRE2 YAML
OPTIONS_DEFAULT=	${OPTIONS_DEFINE:NDEBUG}
OPTIONS_SUB=		yes

JSON_DESC=	JSON output support
PCRE2_DESC=	${PCRE_DESC} v2

DEBUG_CONFIGURE_ENABLE=	debugging

ICONV_USES=		iconv
ICONV_CONFIGURE_ENABLE=	iconv

# Extra support for YAML and XML based languages
JSON_LIB_DEPENDS=	libjansson.so:devel/jansson
JSON_CONFIGURE_ENABLE=	json

LIBXML2_LIB_DEPENDS=		libxml2.so:textproc/libxml2
LIBXML2_CONFIGURE_ENABLE=	xml

MANPAGES_BUILD_DEPENDS=	rst2man:textproc/py-docutils

PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE2_CONFIGURE_ENABLE=	pcre2

YAML_LIB_DEPENDS=	libyaml.so:textproc/libyaml
YAML_CONFIGURE_ENABLE=	yaml

.include <bsd.port.mk>
