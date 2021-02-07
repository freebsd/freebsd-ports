# $FreeBSD$

PORTNAME=	rnnoise
DISTVERSION=	g20210122
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Recurrent neural network for audio noise reduction

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --disable-examples
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	xiph
GH_TAGNAME=	1cbdbcf

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_ENABLE=	doc

PORTDOCS=	* # API documentation feature is broken: https://github.com/xiph/rnnoise/issues/44

PLIST_FILES=	include/rnnoise.h \
		lib/librnnoise.so \
		lib/librnnoise.so.0 \
		lib/librnnoise.so.0.4.1 \
		libdata/pkgconfig/rnnoise.pc

post-install-DOCS-on:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
