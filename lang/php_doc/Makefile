# New ports collection makefile for:	php_doc
# Date created:		Sun Apr 22 14:51:32 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	php_doc
PORTVERSION?=	20100701
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
		korean/php_doc \
		polish/php_doc

PHP_LANG?=	en
PHP_LANGS?=	${PHP_WRKDIR} ${PHP_WRKSRC}
PHP_WRKDIR=	bg br de en fr kr pl ro tr
PHP_WRKSRC=	ja
PHPDOCDIR=	${PREFIX}/share/doc/php-${PHP_LANG}
PLIST=		${WRKDIR}/pkg-plist

.for lang in ${PHP_WRKSRC}
.if ${PHP_LANG} == ${lang}
WRK_SRC=	${WRKDIR}
.endif
.endfor
.for lang in ${PHP_WRKDIR}
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
	@${ECHO} "	bg (bulgarian), br (brazillian), de (german),"
	@${ECHO} "	en (english), fr (french), ja (japanese),"
	@${ECHO} "	kr (korean), pl (polish), ro (romian),"
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
	for f in `${FIND} ${WRK_SRC} -type f ! -name '.*' ! -name pkg-plist | ${SED} -e "s,${WRK_SRC}/,,"`; do \
		${INSTALL_DATA} ${WRK_SRC}/$$f ${PHPDOCDIR}/$$f; \
	done

# this is for the maintainer only

#
# php_manual_fr.html.gz
#
# Download the files from http://au.php.net/distributions/manual/
#
makesum:
	@> ${MD5_FILE}
.for l in ${PHP_LANGS}
	@f=php_manual_${l}-${PORTVERSION}${EXTRACT_SUFX}; \
	${ECHO_CMD} makesum on $${f}; \
	cd ${DISTDIR}; \
	${MD5} $${f} >> ${MD5_FILE}; \
	${SHA256} $${f} >> ${MD5_FILE}; \
	${ECHO_CMD} "SIZE ($${f}) = "`${LS} -ALln $${f} | ${AWK} '{print $$5}'` >> ${MD5_FILE}
.endfor

fetchdist:
.for l in ${PHP_LANGS:S/br/pt_BR/}
#	wget -c ftp://ftp.planetmirror.com/pub/php/distributions/manual/php_manual_${l}.tar.gz
	wget -c  ftp://pt.php.net/pub/php/distributions/manual/php_manual_${l}.tar.gz
	if [ "${l}" = "pt_BR" ]; then \
		${MV} php_manual_${l}.tar.gz ${DISTDIR}/php_manual_br-${PORTVERSION}.tar.gz; \
	else \
		${MV} php_manual_${l}.tar.gz ${DISTDIR}/php_manual_${l}-${PORTVERSION}.tar.gz; \
	fi
.endfor

.include <bsd.port.mk>
