# Created by: Andre Rikkert de Koe - ARK-ICT <andre@ark-ict.nl>
# $FreeBSD$

PORTNAME=	gitlist
DISTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	https://github.com/klaussilveira/gitlist/releases/download/${DISTVERSION}/ \
		http://freebsd.ark-ict.nl/ports/

MAINTAINER=	andre@ark-ict.nl
COMMENT=	Web based Git repository browser written in PHP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	git:devel/git

PLIST=		${WRKDIR}/plist
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
USES=		php:web
USE_PHP=	ctype hash simplexml

USERS?=		${WWWOWN}
GROUPS?=	${WWWGRP}
SUB_FILES=	pkg-message

post-patch:
	${FIND} ${WRKSRC}/vendor/klaussilveira/gitter/lib/Gitter/Model/ -name \*.php -exec ${SED} -i '' 's/Object/Objekt/g' {} \;
	${MV} ${WRKSRC}/vendor/klaussilveira/gitter/lib/Gitter/Model/Object.php ${WRKSRC}/vendor/klaussilveira/gitter/lib/Gitter/Model/Objekt.php
	${MKDIR} ${WRKSRC}/cache
	cd ${WRKSRC}; \
	${REINPLACE_CMD} -e 's|/usr/bin/git|/usr/local/bin/git|g' config.ini-example; \
	${FIND} . ! -type d | ${SORT} | ${SED} -e "s,^\.,%%WWWDIR%%," > ${PLIST};
	${ECHO} "@dir(${WWWOWN},${WWWGRP},) %%WWWDIR%%/cache" >> ${PLIST}

do-install:
	cd ${WRKSRC}; \
	IFS="$$(printf '\n\t')"; \
	for src in $$( ${FIND} . ); do \
		dst="${STAGEDIR}${WWWDIR}$${src#.}"; \
		if ${TEST} -d "$$src"; then \
			${MKDIR} "$$dst"; \
		else \
			${INSTALL_DATA} "$$src" "$$dst"; \
		fi \
	done

.include <bsd.port.mk>
