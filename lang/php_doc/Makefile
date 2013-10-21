# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php_doc
PORTVERSION?=	20131017
CATEGORIES?=	lang
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTNAME=	php_manual_${PHP_LANG}-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT?=	PHP documentation in HTML

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
SLAVEDIRS=	french/php_doc \
		german/php_doc \
		japanese/php_doc \
		polish/php_doc

USE_PHPIZE=	yes
PHP_LANG?=	en
PHP_LANGS?=	${PHP_HTML_CHUNKED} ${PHP_HTML_NORMAL}
PHP_HTML_CHUNKED=	br de en fr ja pl ro tr
PHPDOCDIR=	${PREFIX}/share/doc/php-${PHP_LANG}/
PLIST=		${WRKDIR}/pkg-plist

.for lang in ${PHP_HTML_NORMAL}
.if ${PHP_LANG} == ${lang}
WRK_SRC=	${WRKDIR}/html/
.endif
.endfor
.for lang in ${PHP_HTML_CHUNKED}
.if ${PHP_LANG} == ${lang}
WRK_SRC=	${WRKDIR}/php-chunked-xhtml/
.endif
.endfor

PKGNAMESUFFIX=	-${PHP_LANG}

PLIST_SUB=	PHPDOCDIR=${PHPDOCDIR:S/^${PREFIX}\///}

.if ${PHP_LANG} == en
NO_STAGE=	yes
pre-fetch:
	@${ECHO}
	@${ECHO} "You may set PHP_LANG to"
	@${ECHO} "	br (brazillian), de (german),"
	@${ECHO} "	en (english), fr (french), ja (japanese),"
	@${ECHO} "	pl (polish), ro (romian),"
	@${ECHO} "	tr (turkey)"
	@${ECHO} "to get a different language than the default one (english)."
	@${ECHO}
.endif

pre-install:
	${FIND} ${WRK_SRC} -type f ! -name '.*' ! -name pkg-plist | ${SED} -e "s,${WRK_SRC},%%PHPDOCDIR%%," > ${PLIST}
	${FIND} ${WRK_SRC} -type d | ${SORT} -r | ${SED} -e "s,${WRK_SRC},@dirrm %%PHPDOCDIR%%," >> ${PLIST}

do-install:
	@${MKDIR} ${PHPDOCDIR}
	${FIND} ${WRK_SRC} -type d | ${SED} -e "s,${WRK_SRC},${PHPDOCDIR}/," | ${XARGS} ${MKDIR}
	for f in `${FIND} ${WRK_SRC} -type f ! -name '.*' ! -name pkg-plist | ${SED} -e 's,${WRK_SRC},,'`; do \
		${INSTALL_DATA} ${WRK_SRC}/$$f ${PHPDOCDIR}/$$f; \
	done

# this is for the maintainer only

#
# php_manual_fr.html.gz
#
# Download the files from http://au.php.net/distributions/manual/
#
makesum:
	@> ${DISTINFO_FILE}
.for l in ${PHP_LANGS}
	@f=php_manual_${l}-${PORTVERSION}${EXTRACT_SUFX}; \
	${ECHO_CMD} makesum on $${f}; \
	cd ${DISTDIR}; \
	${SHA256} $${f} >> ${DISTINFO_FILE}; \
	${ECHO_CMD} "SIZE ($${f}) = "`${LS} -ALln $${f} | ${AWK} '{print $$5}'` >> ${DISTINFO_FILE}
.endfor

fetchdist:
.for l in ${PHP_LANGS:S/br/pt_BR/}
	fetch -mv http://au2.php.net/distributions/manual/php_manual_${l}.tar.gz
.endfor
.for l in ${PHP_LANGS:S/br/pt_BR/}
	if [ "${l}" = "pt_BR" ]; then \
		${MV} php_manual_${l}.tar.gz ${DISTDIR}/php_manual_br-${PORTVERSION}.tar.gz; \
	else \
		${MV} php_manual_${l}.tar.gz ${DISTDIR}/php_manual_${l}-${PORTVERSION}.tar.gz; \
	fi
.endfor

.include <bsd.port.mk>
