# New ports collection makefile for:	dbskkd-cdb
# Version required:	1.01
# Date created:		17 Jun 1999
# Whom:			Makoto Matsushita <matusita@jp.FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	dbskkd-cdb-1.01
PKGNAME=	ja-dbskkd-cdb-1.01
CATEGORIES=	japanese
MASTER_SITES=	http://www.k2r.org/kenji/software/

MAINTAINER=	matusita@jp.Freebsd.ORG

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
DOCS=		Release-Notes.English Release-Notes.Japanese LICENSE

MAKE_ENV+=	SKKJISYO=${SKKJISYO}
PLIST_SUB=	JISYONAME=${SKKJISYO}

post-patch:
.for docs in ${DOCS}
	@${SED} -e "s!%%PREFIX%%!${PREFIX}!g" -e "s!%%JISYONAME%%!${SKKJISYO}!g" < ${WRKSRC}/${docs} > ${WRKSRC}/.tmp
	@${MV} -f ${WRKSRC}/.tmp ${WRKSRC}/${docs}
.endfor

post-install:
	@${MKDIR} ${PREFIX}/share/dbskkd-cdb ${PREFIX}/share/doc/dbskkd-cdb
	${INSTALL_DATA} ${WRKSRC}/${SKKJISYO}.cdb ${PREFIX}/share/dbskkd-cdb
.for docs in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${PREFIX}/share/doc/dbskkd-cdb
.endfor

.include <bsd.port.pre.mk>

.if defined(USE_INSTALLED_JISYO) && ${USE_INSTALLED_JISYO} == YES || \
    exists(${LOCALBASE}/share/skk/${SKKJISYO}) && \
    (!defined(USE_INSTALLED_JISYO) || ${USE_INSTALLED_JISYO} != NO)
pre-build::
	@${CP} ${LOCALBASE}/share/skk/${SKKJISYO} ${WRKSRC}
.else
BUILD_DEPENDS+=	/nonexistent:${PORTSDIR}/japanese/skk-jisyo:extract
pre-build::
	@${CP} ${PORTSDIR}/japanese/skk-jisyo/work/*/jisyo/${SKKJISYO} ${WRKSRC}
.endif

.if defined(USE_INSTALLED_CDB) && ${USE_INSTALLED_CDB} == YES || \
    exists(${LOCALBASE}/lib/libcdb.a) && exists(${LOCALBASE}/bin/cdbmake) && \
    (!defined(USE_INSTALLED_CDB) || ${USE_INSTALLED_CDB} != NO)
pre-build::
	@${CP} ${LOCALBASE}/lib/libcdb.a ${LOCALBASE}/bin/cdbmake ${WRKSRC}
	@(cd ${WRKSRC}; SKKJISYO=${SKKJISYO} ./makeskkcdb.sh)
.else
BUILD_DEPENDS+=	/nonexistent:${PORTSDIR}/databases/cdb:build
pre-build::
	@${CP} ${PORTSDIR}/databases/cdb/work/*/libcdb.a ${WRKSRC}
	@${CP} ${PORTSDIR}/databases/cdb/work/*/cdbmake ${WRKSRC}
	@(cd ${WRKSRC}; SKKJISYO=${SKKJISYO} ./makeskkcdb.sh)
.endif

.include <bsd.port.post.mk>
