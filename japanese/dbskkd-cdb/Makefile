# New ports collection makefile for:	dbskkd-cdb
# Date created:		17 Jun 1999
# Whom:			Makoto Matsushita <matusita@jp.FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	dbskkd-cdb
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://www.ne.jp/asahi/bdx/info/software/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${CDB_DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	matusita@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/${SKKDIR}/SKK-JISYO.${SKKJISYO_TYPE}.cdb:${PORTSDIR}/japanese/skk-jisyo-cdb

CDB_DISTNAME=	cdb-0.55

SKKDIR?=	share/skk
SKKJISYO_TYPE?=	L
DOCS=		Release-Notes.English Release-Notes.Japanese LICENSE

MAKE_ENV+=	SKKDIR=${SKKDIR} SKKJISYO=SKK-JISYO.${SKKJISYO_TYPE}

post-patch:
.for docs in ${DOCS}
	${SED} -e "s!%%PREFIX%%!${PREFIX}!g" -e "s!%%SKKDIR%%!${SKKDIR}!g" -e "s!%%JISYONAME%%!SKK-JISYO.${SKKJISYO_TYPE}!g" < ${WRKSRC}/${docs} > ${WRKSRC}/.tmp
	${MV} -f ${WRKSRC}/.tmp ${WRKSRC}/${docs}
.endfor

post-install:
	${MKDIR} ${PREFIX}/share/doc/dbskkd-cdb
.for docs in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${PREFIX}/share/doc/dbskkd-cdb
.endfor

pre-build::
	(cd ${WRKDIR}/${CDB_DISTNAME}; make it)
	${CP} ${WRKDIR}/${CDB_DISTNAME}/libcdb.a ${WRKSRC}
	${CP} ${WRKDIR}/${CDB_DISTNAME}/cdbmake ${WRKSRC}

.include <bsd.port.mk>
