PORTNAME=	rnnoise
PORTVERSION=	0.2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/xiph/rnnoise/releases/download/v${PORTVERSION}/

PATCH_SITES=	https://github.com/xiph/rnnoise/commit/
PATCHFILES=	372f7b4b76cde4ca1ec4605353dd17898a99de38.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Recurrent neural network for audio noise reduction
WWW=		https://jmvalin.ca/demo/rnnoise/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-examples \
		--disable-x86-rtcd
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_ENABLE=	doc

PORTDOCS=	* # API documentation feature is broken: https://github.com/xiph/rnnoise/issues/44

PLIST_FILES=	include/rnnoise.h \
		lib/librnnoise.a \
		lib/librnnoise.so \
		lib/librnnoise.so.0 \
		lib/librnnoise.so.0.4.1 \
		libdata/pkgconfig/rnnoise.pc

post-install-DOCS-on:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
