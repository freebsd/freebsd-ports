# New ports collection makefile for:	dbskkd-cdb
# Date created:		17 Jun 1999
# Whom:			Makoto Matsushita <matusita@jp.FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	dbskkd-cdb
PORTVERSION=	1.01
CATEGORIES=	japanese
MASTER_SITES=	http://www.ne.jp/asahi/bdx/info/software/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${CDB_DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	matusita@jp.FreeBSD.org

CDB_DISTNAME=	cdb-0.55

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
DOCS=		Release-Notes.English Release-Notes.Japanese LICENSE

MAKE_ENV+=	SKKJISYO=${SKKJISYO}
PLIST_SUB=	JISYONAME=${SKKJISYO}

post-patch:
.for docs in ${DOCS}
	${SED} -e "s!%%PREFIX%%!${PREFIX}!g" -e "s!%%JISYONAME%%!${SKKJISYO}!g" < ${WRKSRC}/${docs} > ${WRKSRC}/.tmp
	${MV} -f ${WRKSRC}/.tmp ${WRKSRC}/${docs}
.endfor

post-install:
	${MKDIR} ${PREFIX}/share/dbskkd-cdb ${PREFIX}/share/doc/dbskkd-cdb
	${INSTALL_DATA} ${WRKSRC}/${SKKJISYO}.cdb ${PREFIX}/share/dbskkd-cdb
.for docs in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${PREFIX}/share/doc/dbskkd-cdb
.endfor

.include <bsd.port.pre.mk>

.if defined(WITH_JISYO) || (exists(${LOCALBASE}/share/skk/${SKKJISYO}) \
	&& !defined(WITHOUT_JISYO))
pre-build::
	${CP} ${LOCALBASE}/share/skk/${SKKJISYO} ${WRKSRC}
.else
BUILD_DEPENDS+=	/nonexistent:${.CURDIR}/../../japanese/skk-jisyo:extract
pre-build::
	${CP} ${WRKDIR}/../../../japanese/skk-jisyo/work/*/jisyo/${SKKJISYO} ${WRKSRC}
.endif

pre-build::
	(cd ${WRKDIR}/${CDB_DISTNAME}; make it)
	${CP} ${WRKDIR}/${CDB_DISTNAME}/libcdb.a ${WRKSRC}
	${CP} ${WRKDIR}/${CDB_DISTNAME}/cdbmake ${WRKSRC}
	(cd ${WRKSRC}; SKKJISYO=${SKKJISYO} ./makeskkcdb.sh)

.include <bsd.port.post.mk>
