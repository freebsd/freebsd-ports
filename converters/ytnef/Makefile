PORTNAME=	ytnef
DISTVERSION=	2.1.4
PORTEPOCH=	1
CATEGORIES=	converters mail
MASTER_SITES=	https://github.com/Yeraze/ytnef/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Unpack data in MS Outlook TNEF format
WWW=		https://github.com/Yeraze/ytnef

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash>0:shells/bash \
		gnugrep>0:textproc/gnugrep
RUN_DEPENDS=	p5-MIME-Tools>=0:mail/p5-MIME-Tools

USES=		cpe libtool perl5 shebangfix tar:bz2
CPE_VENDOR=	ytnef_project
USE_LDCONFIG=	yes
USE_PERL5=	run

SHEBANG_FILES=	test-data/test.sh ytnef/ytnefprocess
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static=no
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

BINARY_ALIAS=	grep=ggrep

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/ytnef/ytnefprocess

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
