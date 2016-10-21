# Created by: abgoeree@uwnet.nl
# $FreeBSD$

PORTNAME=	adodb
PORTVERSION=	4.99.2
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-php-4-and-5/${PORTNAME}-${PORTVERSION:S/.//g}-for-php
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Database library for PHP

LICENSE=	BSD4CLAUSE LGPL21
LICENSE_COMB=	dual

USES=		tar:tgz
USE_PHP=	pcre

CONFLICTS=	adodb-5.*

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

ADODB_SUBDIRS=	contrib datadict drivers lang pear perf session xsl

OPTIONS_DEFINE=	TESTS DOCS
OPTIONS_SUB=	yes

TESTS_DESC=	Install tests

post-patch:
	@cd ${WRKSRC}; ${RM} cute_icons_for_site/Thumbs.db

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}; ${FIND} ${ADODB_SUBDIRS} -type d \
		-exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \;
	@cd ${WRKSRC}; ${FIND} . ! -path './*/*' -type f \( -name '*.php' -or -name '*.dtd' -or -name '*.zip' \) \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;
	@cd ${WRKSRC}; ${FIND} ${ADODB_SUBDIRS} -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;

do-install-TESTS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/tests
	@cd ${WRKSRC}; ${FIND} tests -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/cute_icons_for_site
	@cd ${WRKSRC}; ${FIND} . ! -path './*/*' -type f -name '*.txt' \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DOCSDIR}/{} \;
	@cd ${WRKSRC}/docs; ${FIND} . -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/docs/{} ${STAGEDIR}${DOCSDIR}/{} \;
	@cd ${WRKSRC}; ${FIND} cute_icons_for_site -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DOCSDIR}/{} \;

.include <bsd.port.mk>
