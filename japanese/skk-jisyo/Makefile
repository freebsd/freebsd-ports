# New ports collection makefile for:	skk-jisyo
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skk-jisyo
PORTVERSION=	200605
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= matusita/${PORTNAME}
.if defined(WITH_SKKJISYO_CDB)
PKGNAMESUFFIX=	-cdb
.endif
DIST_SUBDIR=	skk-jisyo

MAINTAINER?=	matusita@FreeBSD.org
COMMENT?=	Jisyo (dictionary) files for the SKK Japanese-input software

.if defined(WITH_SKKJISYO_CDB)
BUILD_DEPENDS=	${LOCALBASE}/bin/cdbmake:${PORTSDIR}/databases/cdb
.endif

SKKDIR?=	share/skk
SKK_JISYO_TYPE?=L M S

USE_BZIP2=		yes
NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	${WRKDIR}
PLIST_SUB+=		SKKDIR=${SKKDIR}
.for type in ${SKK_JISYO_TYPE}
DISTFILES+=		SKK-JISYO.${type}.${PORTVERSION}.bz2
PLIST_FILES+=		${SKKDIR}/SKK-JISYO.${type}${CDBSUFFIX}
.endfor

.if defined(WITH_SKKJISYO_CDB)
CDBSUFFIX=		.cdb
.else
CDBSUFFIX=		#empty
NO_BUILD=		yes
.endif

post-extract:
	@(cd ${WRKDIR}; ${BZIP2_CMD} -d *.bz2)

.if defined(WITH_SKKJISYO_DELCOMMENTS)
# Strip comments in transtation candidates list.
# Candidate list starts with '/', and each candidate is concatinated by
# '/' (e.g., "/c1/c2/".)  Each candidate may have a comment just after
# the candidate, leading a marker character ';' (e.g. /c3;comment/).
do-patch:
.for type in ${SKK_JISYO_TYPE}
	${REINPLACE_CMD} -e '/^[^;]/s,;[^/]*/,/,g' \
		${WRKDIR}/SKK-JISYO.${type}.${PORTVERSION}
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
			k = $$1; didx = index($$0, $$2); \
			d = substr($$0, didx); \
			print "+" length(k) "," length(d) ":" k "->" d; \
		} \
		END { \
			print ""; \
		}' \
		< ${WRKDIR}/SKK-JISYO.${type}.${PORTVERSION} | \
	${LOCALBASE}/bin/cdbmake \
		${WRKDIR}/SKK-JISYO.${type}.${PORTVERSION}${CDBSUFFIX} \
		${WRKDIR}/SKK-JISYO.${type}.${PORTVERSION}.tmp
.endfor
.endif

do-install:
	${MKDIR} ${PREFIX}/${SKKDIR}
.for type in ${SKK_JISYO_TYPE}
	${INSTALL_DATA} ${WRKSRC}/SKK-JISYO.${type}.${PORTVERSION}${CDBSUFFIX} \
		${PREFIX}/${SKKDIR}/SKK-JISYO.${type}${CDBSUFFIX}
.endfor

.include <bsd.port.mk>
