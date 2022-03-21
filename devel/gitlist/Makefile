# Created by: Andre Rikkert de Koe - ARK-ICT <andre@ark-ict.nl>

PORTNAME=	gitlist
DISTVERSION=	1.1.1
CATEGORIES=	devel www
MASTER_SITES=	https://github.com/klaussilveira/gitlist/releases/download/${DISTVERSION}/ \
		https://freebsd.ark-ict.nl/ports/

MAINTAINER=	freebsd-ports@misc.ark-ict.nl
COMMENT=	Web based Git repository browser written in PHP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	git:devel/git

NO_BUILD=	yes
USES=		cpe php:web zip
USE_PHP=	ctype hash json simplexml

PLIST=		${WRKDIR}/plist
NO_WRKSUBDIR=	yes

USERS?=		${WWWOWN}
GROUPS?=	${WWWGRP}
SUB_FILES=	pkg-message

post-patch:
	${MKDIR} ${WRKSRC}/cache
	cd ${WRKSRC}; \
	${REINPLACE_CMD} -e 's|/usr/bin/git|/usr/local/bin/git|g' config.ini-example; \
	${FIND} . ! -type d | ${SORT} | ${SED} -e "s,^\.,%%WWWDIR%%," > ${PLIST};
	${ECHO} "@dir(${WWWOWN},${WWWGRP},) %%WWWDIR%%/vendor/twig/twig/doc" >> ${PLIST}
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
	${RM} -r "${WWWDIR}/cache/views"

.include <bsd.port.mk>
