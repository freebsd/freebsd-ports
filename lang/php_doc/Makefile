# New ports collection makefile for:	php_doc
# Date created:		Sun Apr 22 14:51:32 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	php_doc
PORTVERSION=	1.20020119
CATEGORIES?=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dirk
DISTNAME=	php_manual_${PHP_LANG}

MAINTAINER=	dirk@FreeBSD.org

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
SLAVEDIRS=	french/php_doc german/php_doc japanese/php_doc
USE_BZIP2=	YES

PHP_LANG?=	en
PHPDOCDIR=	${PREFIX}/share/doc/php

.if ${PHP_LANG} != en
PKGNAMEPREFIX=	${PHP_LANG}-
PLIST=		${PKGDIR}/pkg-plist.${PHP_LANG}
PHPDOCDIR=	${PREFIX}/share/doc/${PHP_LANG}-php

.if ${PHP_LANG} == de
PORTVERSION=	1.20020119
.endif
.if ${PHP_LANG} == es
PORTVERSION=	1.20020105
.endif
.if ${PHP_LANG} == fr
PORTVERSION=	1.20020105
.endif
.if ${PHP_LANG} == ja
PORTVERSION=	1.20020104
.endif
.endif

PLIST_SUB=	PHPDOCDIR=${PHPDOCDIR:S/^${PREFIX}\///}

.if ${PHP_LANG} == en
pre-fetch:
	@${ECHO}
	@${ECHO} "You may set PHP_LANG to"
	@${ECHO} "	de (german),"
	@${ECHO} "	es (spanish),"
	@${ECHO} "	fr (french) or"
	@${ECHO} "	ja (japanese)"
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
DISTSITE?=	http://www.php.net/distributions/manual/

localfetch:
.for lang in de en es fr ja
	${MKDIR} ${LOCAL_DISTDIR}
	[ -f ${LOCAL_DISTDIR}/php_manual_${lang}${EXTRACT_SUFX} ] || \
	${FETCH_CMD} -o ${LOCAL_DISTDIR}/php_manual_${lang}${EXTRACT_SUFX} ${DISTSITE}php_manual_${lang}${EXTRACT_SUFX}

	${MKDIR} ${LOCAL_TMPDIR}/${lang}
	cd ${LOCAL_TMPDIR}/${lang} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${LOCAL_DISTDIR}/php_manual_${lang}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}

	(cd ${LOCAL_TMPDIR}/${lang} && /bin/ls -1) | ${PERL} -pe 'print "%%PHPDOCDIR%%/$_";' > ${.CURDIR}/pkg-plist.${lang}
	${ECHO} "@dirrm %%PHPDOCDIR%%" >> ${.CURDIR}/pkg-plist.${lang}
	${RM} -rf ${LOCAL_TMPDIR}/${lang}
.endfor

	${MV} ${.CURDIR}/pkg-plist.en ${.CURDIR}/pkg-plist
	cd ${LOCAL_DISTDIR} && ${MD5} php_manual_* > ${.CURDIR}/distinfo
.endif

.include <bsd.port.mk>
