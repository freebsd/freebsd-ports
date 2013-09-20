# Created by: abgoeree@uwnet.nl
# $FreeBSD$

PORTNAME=	adodb
PORTVERSION=	4.99.2
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-php-4-and-5/${PORTNAME}-${PORTVERSION:S/.//g}-for-php
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	joehorn@gmail.com
COMMENT=	Database library for PHP

LICENSE=	BSD

USE_PHP=	pcre

CONFLICTS=	adodb-5.*

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES

ADODB_SUBDIRS=	contrib datadict drivers lang pear perf session xsl

OPTIONS_DEFINE=	TESTS DOCS
TESTS_DESC=	Install tests

NO_STAGE=	yes
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
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}; ${FIND} ${ADODB_SUBDIRS} -type d \
		-exec ${MKDIR} ${DATADIR}/{} \;
	@cd ${WRKSRC}; ${FIND} . ! -path './*/*' -type f \( -name '*.php' -or -name '*.dtd' -or -name '*.zip' \) \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${DATADIR}/{} \;
	@cd ${WRKSRC}; ${FIND} ${ADODB_SUBDIRS} -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${DATADIR}/{} \;

.if ${PORT_OPTIONS:MTESTS}
	@${MKDIR} ${DATADIR}/tests
	@cd ${WRKSRC}; ${FIND} tests -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${DATADIR}/{} \;
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/cute_icons_for_site
	@cd ${WRKSRC}; ${FIND} . ! -path './*/*' -type f -name '*.txt' \
		-exec ${INSTALL_MAN} ${WRKSRC}/{} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}/docs; ${FIND} . -type f \
		-exec ${INSTALL_MAN} ${WRKSRC}/docs/{} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}; ${FIND} cute_icons_for_site -type f \
		-exec ${INSTALL_MAN} ${WRKSRC}/{} ${DOCSDIR}/{} \;
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
