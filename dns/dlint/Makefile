PORTNAME=	dlint
DISTVERSION=	1.4.3
CATEGORIES=	dns
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Lint for DNS zones -- a Domain Name Server zone verification utility
WWW=		https://codeberg.org/BSDforge/${PORTNAME}/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	dig:dns/bind-tools

USES=		perl5 shebangfix
SHEBANG_FILES=	digparse
NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-configure:
	@${REINPLACE_CMD} -e 's:/usr/local/bin:${PREFIX}/sbin:g' ${WRKSRC}/dlint
	@${SED} -e 's:DLINT 1:DLINT 8:g' ${WRKSRC}/dlint.1  >${WRKSRC}/dlint.8

do-install:
	cd ${WRKSRC} ; ${INSTALL_SCRIPT} dlint digparse \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dlint.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
