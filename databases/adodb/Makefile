# Created by: abgoeree@uwnet.nl
# $FreeBSD$

PORTNAME=	adodb
PORTVERSION=	4.99.2
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-php-4-and-5/${PORTNAME}-${PORTVERSION:S/.//g}-for-php
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Database library for PHP

LICENSE=	BSD4CLAUSE

USE_PHP=	pcre

CONFLICTS=	adodb-5.*

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES

ADODB_SUBDIRS=	contrib datadict drivers lang pear perf session xsl

OPTIONS_DEFINE=	TESTS DOCS
TESTS_DESC=	Install tests

.include <bsd.port.options.mk>

SUB_FILES+=	pkg-message

.if ${PORT_OPTIONS:MTESTS}
PLIST_SUB+=	TESTS=
.else
PLIST_SUB+=	TESTS="@comment "
.endif

post-patch:
	@cd ${WRKSRC}; ${RM} -f cute_icons_for_site/Thumbs.db

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}; ${FIND} ${ADODB_SUBDIRS} -type d \
		-exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \;
	@cd ${WRKSRC}; ${FIND} . ! -path './*/*' -type f \( -name '*.php' -or -name '*.dtd' -or -name '*.zip' \) \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;
	@cd ${WRKSRC}; ${FIND} ${ADODB_SUBDIRS} -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;

.if ${PORT_OPTIONS:MTESTS}
	@${MKDIR} ${STAGEDIR}${DATADIR}/tests
	@cd ${WRKSRC}; ${FIND} tests -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/cute_icons_for_site
	@cd ${WRKSRC}; ${FIND} . ! -path './*/*' -type f -name '*.txt' \
		-exec ${INSTALL_MAN} ${WRKSRC}/{} ${STAGEDIR}${DOCSDIR}/{} \;
	@cd ${WRKSRC}/docs; ${FIND} . -type f \
		-exec ${INSTALL_MAN} ${WRKSRC}/docs/{} ${STAGEDIR}${DOCSDIR}/{} \;
	@cd ${WRKSRC}; ${FIND} cute_icons_for_site -type f \
		-exec ${INSTALL_MAN} ${WRKSRC}/{} ${STAGEDIR}${DOCSDIR}/{} \;
.endif

.include <bsd.port.mk>
