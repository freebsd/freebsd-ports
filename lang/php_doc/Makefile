# New ports collection makefile for:	php_doc
# Date created:		Sun Apr 22 14:51:32 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	php_doc
PORTVERSION=	20041012
CATEGORIES?=	lang
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTNAME=	php_manual_${PHP_LANG}-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	PHP documentation in HTML

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
SLAVEDIRS=	french/php_doc german/php_doc japanese/php_doc polish/php_doc portugese/php_doc

PHP_LANG?=	en
PHPDOCDIR=	${PREFIX}/share/doc/php-${PHP_LANG}
PLIST=		${WRKDIR}/pkg-plist

PKGNAMESUFFIX=	-${PHP_LANG}

PLIST_SUB=	PHPDOCDIR=${PHPDOCDIR:S/^${PREFIX}\///}

.if ${PHP_LANG} == en
pre-fetch:
	@${ECHO}
	@${ECHO} "You may set PHP_LANG to"
	@${ECHO} "	br (brazillian),"
	@${ECHO} "	de (german),"
	@${ECHO} "	es (spanish),"
	@${ECHO} "	fr (french) or"
	@${ECHO} "	ja (japanese)"
	@${ECHO} "	pl (polish)"
	@${ECHO} "to get a different language than the default one (english)."
	@${ECHO}
.endif

pre-install:
	${FIND} ${WRKDIR} -type f ! -name '.*' ! -name pkg-plist | ${SED} -e "s,${WRKDIR},%%PHPDOCDIR%%," > ${PLIST}
	${FIND} ${WRKDIR} -type d | ${SORT} -r | ${SED} -e "s,${WRKDIR},@dirrm %%PHPDOCDIR%%," >> ${PLIST}

do-install:
	@${MKDIR} ${PHPDOCDIR}
	${FIND} ${WRKDIR} -type d | ${SED} -e "s,${WRKDIR},${PHPDOCDIR}/," | ${XARGS} ${MKDIR}
	for f in `${FIND} ${WRKDIR} -type f ! -name '.*' ! -name pkg-plist | ${SED} -e "s,${WRKDIR}/,,"`; do \
		${INSTALL_DATA} ${WRKDIR}/$$f ${PHPDOCDIR}/$$f; \
	done

# this is for the maintainer only
.if defined(MAINTAINER_MODE)
LOCAL_DISTDIR?=	/var/tmp/php_doc/php
LOCAL_TMPDIR?=	/var/tmp/php_doc/tmp
DISTSITE?=	http://de.php.net/distributions/manual/

localfetch:
.for lang in br de en es fr ja
	${MKDIR} ${LOCAL_DISTDIR}
	[ -f ${LOCAL_DISTDIR}/php_manual_${lang}${EXTRACT_SUFX} ] || \
	${FETCH_CMD} -o ${LOCAL_DISTDIR}/php_manual_${lang}${EXTRACT_SUFX} ${DISTSITE}php_manual_${lang}${EXTRACT_SUFX}

	${MKDIR} ${LOCAL_TMPDIR}/${lang}
	cd ${LOCAL_TMPDIR}/${lang} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${LOCAL_DISTDIR}/php_manual_${lang}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}

	(cd ${LOCAL_TMPDIR}/${lang} && ${LS} -1) | ${PERL} -pe 'print "%%PHPDOCDIR%%/$_";' > ${.CURDIR}/pkg-plist.${lang}
	${ECHO_CMD} "@dirrm %%PHPDOCDIR%%" >> ${.CURDIR}/pkg-plist.${lang}
	${RM} -rf ${LOCAL_TMPDIR}/${lang}
.endfor

	${MV} ${.CURDIR}/pkg-plist.en ${.CURDIR}/pkg-plist
	cd ${LOCAL_DISTDIR} && ${MD5} php_manual_* > ${.CURDIR}/distinfo
.endif

.include <bsd.port.mk>
