PORTNAME=	ytnef
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.2
PORTEPOCH=	1
CATEGORIES=	converters mail

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Unpack data in MS Outlook TNEF format
WWW=		https://github.com/Yeraze/ytnef

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-MIME-Tools>=0:mail/p5-MIME-Tools

USES=		autoreconf cpe libtool perl5 shebangfix
CPE_VENDOR=	ytnef_project
USE_GITHUB=	yes
GH_ACCOUNT=	Yeraze
USE_LDCONFIG=	yes
USE_PERL5=	run

SHEBANG_FILES=	ytnef/ytnefprocess
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/ytnef/ytnefprocess

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
