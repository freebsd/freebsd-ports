# New ports collection makefile for:	php_doc
# Date created:		Sun Apr 22 14:51:32 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	php_doc
PORTVERSION=	1.1
CATEGORIES?=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dirk/php/${PHP_LANG}
DISTNAME=	manual

MAINTAINER=	dirk@FreeBSD.org

DIST_SUBDIR=	php/${PHP_LANG}
NO_BUILD=	YES
NO_WRKSUBDIR=	YES
SLAVEDIRS=	french/php_doc german/php_doc

PHP_LANG?=	en
PHPDOCDIR=	${PREFIX}/share/doc/php

.if ${PHP_LANG} != en
PKGNAMEPREFIX=	${PHP_LANG}-
PLIST=		${PKGDIR}/pkg-plist.${PHP_LANG}
PHPDOCDIR=	${PREFIX}/share/doc/${PHP_LANG}-php
.endif

PLIST_SUB=	PHPDOCDIR=${PHPDOCDIR:S/^${PREFIX}\///}

.if ${PHP_LANG} == en
pre-fetch:
	@${ECHO}
	@${ECHO} "You may set PHP_LANG to"
	@${ECHO} "	de (german),"
	@${ECHO} "	es (spanish) or"
	@${ECHO} "	fr (french)"
	@${ECHO} "to get a different language than the default one (english)."
	@${ECHO}
.endif

do-install:
	@${MKDIR} ${PHPDOCDIR}
	@for i in ${WRKSRC}/*; do \
		${INSTALL_DATA} $$i ${PHPDOCDIR}; \
	done

# this is for the maintainer only
.if defined(MAINTAINER_MODE)
LOCAL_DISTDIR?=	/var/tmp/php_doc/php
LOCAL_TMPDIR?=	/var/tmp/php_doc/tmp
DISTSITE?=	http://php.he.net/manual/

localfetch:
.for lang in de en es fr
	${MKDIR} ${LOCAL_DISTDIR}/${lang}
	${FETCH_CMD} -o ${LOCAL_DISTDIR}/${lang}/manual.tar.gz ${DISTSITE}/${lang}/manual.tar.gz

	${MKDIR} ${LOCAL_TMPDIR}/${lang}
	${TAR} -C ${LOCAL_TMPDIR}/${lang} -xzf ${LOCAL_DISTDIR}/${lang}/manual.tar.gz

	(cd ${LOCAL_TMPDIR}/${lang} && /bin/ls -1) | ${PERL} -pe 'print "%%PHPDOCDIR%%/$_";' > ${.CURDIR}/pkg-plist.${lang}
	${ECHO} "@dirrm %%PHPDOCDIR%%" >> ${.CURDIR}/pkg-plist.${lang}
	${RM} -rf ${LOCAL_TMPDIR}/${lang}
.endfor

	${MV} ${.CURDIR}/pkg-plist.en ${.CURDIR}/pkg-plist
	cd ${LOCAL_DISTDIR}/.. && ${MD5} php/*/* > ${.CURDIR}/distinfo
.endif

.include <bsd.port.mk>
