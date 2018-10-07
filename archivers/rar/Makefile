# Created by: ache
# $FreeBSD$

PORTNAME=	rar
PORTVERSION=	5.6.1
PORTEPOCH=	3
CATEGORIES=	archivers
MASTER_SITES=	https://www.rarlab.com/rar/
DISTNAME=	rarbsd-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	File archiver (binary port)

LICENSE=	RAR
LICENSE_NAME=	RAR license
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RESTRICTED=	only unmodified original package can be distributed

IA32_BINARY_PORT=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rar

PLIST_FILES=	bin/rar lib/default.sfx etc/rarfiles.lst man/cat1/rar.1.gz

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${STAGEDIR}${PREFIX}/man/cat1/rar.1
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${STAGEDIR}${PREFIX}/lib

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${WRKSRC}/order.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
