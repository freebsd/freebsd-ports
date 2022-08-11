PORTNAME=	phpbb
PORTVERSION=	3.0.12
PORTREVISION=	0
CATEGORIES=	chinese www
MASTER_SITES=	http://www.phpbb-tw.net/phpbb/download/ \
		http://freebsd.ee.ccu.edu.tw/phpBB/
PKGNAMESUFFIX=	3-tw
DISTNAME=	phpBB-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Traditional Chinese version of phpBB3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING

CONFLICTS_INSTALL=	phpbb phpbb3 zh-phpbb-tw # share/doc/phpbb/AUTHORS share/doc/phpbb/CHANGELOG.html

USES=		zip

# The phpBB3 port supports a number of variables that may be tweaked at build
# time.  Perform a "make options" to see more information on these variables.
#
WWWDOCROOT?=	www
PHPBBURL?=	phpBB3
#
# End of user-configurable variables.

WRKSRC=		${WRKDIR}/phpBB3
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PHPBBURL="${PHPBBURL}" \
		PHPBBDIR="${PHPBBDIR}"

PORTDOCS=	*
PLIST_SUB+=	PHPBBDIR=${PHPBBDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

# Set custom variables:
#
PHPBBDIR=	${WWWDOCROOT}/${PHPBBURL}
PKGOPTS=	${FILESDIR}/pkg-opts

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

options:
	@ ${ECHO_MSG} "===>  Build options for ${PKGNAME}:"
	@ ${CAT} ${PKGOPTS}

pre-everything::
.if !defined(BATCH)
	@ ${TEST} -r ${PKGOPTS} && \
	  (${ECHO_MSG} '-------------------------------------------------------------------------'; \
	   ${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	   ${ECHO_MSG} '-------------------------------------------------------------------------')
.endif

do-install:
	@ cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${PHPBBDIR} "! -name config.php"
	@ ${TOUCH} ${STAGEDIR}${PREFIX}/${PHPBBDIR}/config.php.sample
	@ ${CHMOD} -R 0755 ${STAGEDIR}${PREFIX}/${PHPBBDIR}

post-install-DOCS-on:
	@ ${MKDIR} ${STAGEDIR}${DOCSDIR}
	@ cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
