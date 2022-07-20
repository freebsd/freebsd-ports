PORTNAME=	ytnef
PORTVERSION=	1.9.3
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	converters mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unpack data in MS Outlook TNEF format

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-MIME-Tools>=0:mail/p5-MIME-Tools

USES=		autoreconf cpe libtool pathfix perl5 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	Yeraze

CPE_VENDOR=	ytnef_project
USE_PERL5=	run

SHEBANG_FILES=	ytnef/ytnefprocess
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/ytnef/ytnefprocess

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
