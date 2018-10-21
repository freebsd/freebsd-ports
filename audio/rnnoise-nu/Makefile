# $FreeBSD$

PORTNAME=	rnnoise-nu
DISTVERSION=	g20180916
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Recurrent neural network for audio noise reduction

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --disable-examples
USE_GITHUB=	yes
GH_ACCOUNT=	GregorR
GH_TAGNAME=	2626930
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_ENABLE=	doc

PORTDOCS=	* # API documentation feature is broken: https://github.com/xiph/rnnoise/issues/44

PLIST_FILES=	include/rnnoise-nu.h \
		lib/librnnoise-nu.so \
		lib/librnnoise-nu.so.1 \
		lib/librnnoise-nu.so.1.0.0 \
		libdata/pkgconfig/rnnoise-nu.pc

post-install-DOCS-on:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
