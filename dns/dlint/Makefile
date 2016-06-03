# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	dlint
PORTVERSION=	1.4.0
CATEGORIES=	dns
MASTER_SITES=	http://www.sfr-fresh.com/unix/misc/dns/ \
		http://www.sourcefiles.org/Networking/Tools/DNS/
DISTNAME=	dlint${PORTVERSION}

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Lint for DNS zones (Domain Name Server zone verification utility)

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
USES=		shebangfix
NO_BUILD=	yes

SHEBANG_FILES=	digparse

OPTIONS_DEFINE=	DOCS

do-configure:
	@${REINPLACE_CMD} -e 's:/usr/local/bin:${PREFIX}/sbin:g' ${WRKSRC}/dlint
	@${SED} -e 's:DLINT 1:DLINT 8:g' ${WRKSRC}/dlint.1  >${WRKSRC}/dlint.8

do-install:
	cd ${WRKSRC} ; ${INSTALL_SCRIPT} dlint digparse \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dlint.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
