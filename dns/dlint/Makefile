PORTNAME=	dlint
PORTVERSION=	1.4.1
CATEGORIES=	dns
MASTER_SITES=	https://BSDforge.com/projects/source/dns/dlint/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Lint for DNS zones (Domain Name Server zone verification utility)
WWW=		https://BSDforge.com/projects/dns/dlint

USES=		shebangfix tar:xz
NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	digparse

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
