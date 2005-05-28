# New ports collection makefile for:	php_doc
# Date created:		Sun Apr 22 14:51:32 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	php_doc
PORTVERSION=	20050521
PORTREVISION=	1
CATEGORIES?=	lang
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTNAME=	php_manual_${PHP_LANG}-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	PHP documentation in HTML

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
SLAVEDIRS=	arabic/php_doc \
		chinese/php_doc-hk \
		chinese/php_doc-tw \
		chinese/php_doc-zh \
		french/php_doc \
		german/php_doc \
		hungarian/php_doc \
		japanese/php_doc \
		korean/php_doc \
		polish/php_doc \
		portugese/php_doc \
		russian/php_doc

PHP_LANG?=	en
PHPDOCDIR=	${PREFIX}/share/doc/php-${PHP_LANG}
PLIST=		${WRKDIR}/pkg-plist

.for lang in hk ja kr
.if ${PHP_LANG} == ${lang}
WRK_SRC=	${WRKDIR}
.endif
.endfor
.for lang in ar br de en fr hu pl ru tw zh
.if ${PHP_LANG} == ${lang}
WRK_SRC=	${WRKDIR}/html
.endif
.endfor

PKGNAMESUFFIX=	-${PHP_LANG}

PLIST_SUB=	PHPDOCDIR=${PHPDOCDIR:S/^${PREFIX}\///}

.if ${PHP_LANG} == en
pre-fetch:
	@${ECHO}
	@${ECHO} "You may set PHP_LANG to"
	@${ECHO} "	ar (arabic),"
	@${ECHO} "	br (brazillian),"
	@${ECHO} "	de (german),"
	@${ECHO} "	en (english),"
	@${ECHO} "	fr (french) or"
	@${ECHO} "	hu (hungarian) or"
	@${ECHO} "	ja (japanese)"
	@${ECHO} "	hk (Chinese Hong Kong Cantonese)"
	@${ECHO} "	kr (korean)"
	@${ECHO} "	pl (polish)"
	@${ECHO} "	ru (russian)"
	@${ECHO} "	tw (Chinese traditional)"
	@${ECHO} "	zh (Chinese Simplified)"
	@${ECHO} "to get a different language than the default one (english)."
	@${ECHO}
.endif

pre-install:
	${FIND} ${WRK_SRC} -type f ! -name '.*' ! -name pkg-plist | ${SED} -e "s,${WRK_SRC},%%PHPDOCDIR%%," > ${PLIST}
	${FIND} ${WRK_SRC} -type d | ${SORT} -r | ${SED} -e "s,${WRK_SRC},@dirrm %%PHPDOCDIR%%," >> ${PLIST}

do-install:
	@${MKDIR} ${PHPDOCDIR}
	${FIND} ${WRK_SRC} -type d | ${SED} -e "s,${WRK_SRC},${PHPDOCDIR}/," | ${XARGS} ${MKDIR}
	for f in `${FIND} ${WRK_SRC} -type f ! -name '.*' ! -name pkg-plist | ${SED} -e "s,${WRK_SRC}/,,"`; do \
		${INSTALL_DATA} ${WRK_SRC}/$$f ${PHPDOCDIR}/$$f; \
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
