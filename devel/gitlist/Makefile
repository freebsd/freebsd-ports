# Created by: Andre Rikkert de Koe - ARK-ICT <andre@ark-ict.nl>
# $FreeBSD$

PORTNAME=	gitlist
PORTVERSION=	0.5.0
CATEGORIES=	devel www
MASTER_SITES=	https://s3.amazonaws.com/gitlist/ \
		http://freebsd.ark-ict.nl/ports/

MAINTAINER=	andre@ark-ict.nl
COMMENT=	Web based Git repository browser written in PHP

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	git:devel/git

PLIST=		${WRKDIR}/plist
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
WANT_PHP_WEB=	yes

USERS?=		${WWWOWN}
GROUPS?=	${WWWGRP}
SUB_FILES=	pkg-message

post-patch:
	${MKDIR} ${WRKSRC}/cache
	cd ${WRKSRC}; \
	${REINPLACE_CMD} -e 's|/usr/bin/git|/usr/local/bin/git|g' config.ini-example; \
	${FIND} . ! -type d | ${SORT} | ${SED} -e "s,^\.,%%WWWDIR%%," > ${PLIST};
	${ECHO} "@dir %%WWWDIR%%/vendor/phpmd/phpmd/setup" >> ${PLIST}
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
