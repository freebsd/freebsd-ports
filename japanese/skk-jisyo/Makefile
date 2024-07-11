PORTNAME=	skk-jisyo
DISTVERSIONPREFIX=	g
DISTVERSION=	20240130
PORTREVISION=	1
CATEGORIES=	japanese
.if defined(WITH_SKKJISYO_CDB)
PKGNAMESUFFIX=	-cdb
.endif

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT?=	Jisyo (dictionary) files for the SKK Japanese-input software
WWW=		http://openlab.jp/skk/dic.html

LICENSE=	GPLv2+

.if defined(WITH_SKKJISYO_CDB)
BUILD_DEPENDS=	${LOCALBASE}/bin/cdb:databases/tinycdb
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	skk-dev
GH_PROJECT=	dict
GH_TAGNAME=	b798a46

NOARCH=		yes

.if defined(WITH_SKKJISYO_CDB)
CDBSUFFIX=		.cdb
.else
CDBSUFFIX=		#empty
NO_BUILD=		yes
.endif

SKKDIR?=	share/skk
SKK_JISYO_TYPE?=L M S JIS2 JIS3_4

.for type in ${SKK_JISYO_TYPE}
PLIST_FILES+=		${SKKDIR}/SKK-JISYO.${type}${CDBSUFFIX}
.endfor
PLIST_SUB+=		SKKDIR=${SKKDIR}

.if defined(WITH_SKKJISYO_DELCOMMENTS)
# Strip comments in transtation candidates list.
# Candidate list starts with '/', and each candidate is concatenated by
# '/' (e.g., "/c1/c2/".)  Each candidate may have a comment just after
# the candidate, leading a marker character ';' (e.g. /c3;comment/).
post-patch:
.for type in ${SKK_JISYO_TYPE}
	${REINPLACE_CMD} -e '/^[^;]/s,;[^/]*/,/,g' -e '/^>/d' \
		${WRKSRC}/SKK-JISYO.${type}
.endfor
.endif

.if defined(WITH_SKKJISYO_CDB)
# Convert plaintext jisyo data to CDB database by cdbmake.
# Each line consists of "+${klen},${dlen}:${key}->${data}", where klen/dlen
# are length of key/data.  A blank line at the end of data is required.
# See also: <URL:http://cr.yp.to/cdb/cdbmake.html>.
do-build:
.for type in ${SKK_JISYO_TYPE}
	${AWK} '/^[^;]/ { \
			s = substr($$0, index($$0, " ") + 1); \
			print "+" length($$1) "," length(s) ":" $$1 "->" s; \
		} \
		END { \
			print ""; \
		}' \
		< ${WRKSRC}/SKK-JISYO.${type} | \
	${LOCALBASE}/bin/cdb -c -t - \
		${WRKSRC}/SKK-JISYO.${type}${CDBSUFFIX}
.endfor
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SKKDIR}
.for type in ${SKK_JISYO_TYPE}
	${INSTALL_DATA} ${WRKSRC}/SKK-JISYO.${type}${CDBSUFFIX} \
		${STAGEDIR}${PREFIX}/${SKKDIR}/
.endfor

.include <bsd.port.mk>
