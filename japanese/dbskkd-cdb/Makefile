# New ports collection makefile for:	dbskkd-cdb
# Date created:		17 Jun 1999
# Whom:			Makoto Matsushita <matusita@jp.FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	dbskkd-cdb
PORTVERSION=	2.00
#PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
#DISTVERSIONSUFFIX=

MAINTAINER=	matusita@FreeBSD.org
COMMENT=Yet another dictionary server for SKK

BUILD_DEPENDS=	${LOCALBASE}/lib/libcdb.a:${PORTSDIR}/databases/tinycdb
RUN_DEPENDS=	${SKKJISYOCDB}:${PORTSDIR}/japanese/skk-jisyo-cdb

PLIST_FILES=	libexec/dbskkd-cdb

SKKDIR?=	share/skk
SKKJISYO_TYPE?=	L
SKKJISYOCDB?=	${LOCALBASE}/${SKKDIR}/SKK-JISYO.${SKKJISYO_TYPE}.cdb

MAKE_ENV+=	LOCALBASE="${LOCALBASE}" CFLAGS="${CFLAGS}"
MAKE_ENV+=	SKKJISYOCDB="${SKKJISYOCDB}"
.if !defined(NOPORTDOCS)
PORTDOCS=	${PORTDOCS_FILE} ${PORTDOCS_SH}
PORTDOCS_FILE=	CHANGES LICENSE READMEJP \
		example-daemontools.txt example-inetd.txt
PORTDOCS_SH=	makeskkcdb.sh skktocdbm.sh
.endif

.include <bsd.port.pre.mk>

post-patch:
.for f in READMEJP makeskkcdb.sh
	${REINPLACE_CMD} -e "s!%%PREFIX%%!${PREFIX}!g" -e "s!%%SKKDIR%%!${SKKDIR}!g" -e "s!%%JISYONAME%%!SKK-JISYO.${SKKJISYO_TYPE}!g" ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbskkd-cdb ${PREFIX}/libexec
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS_FILE}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.for docs in ${PORTDOCS_SH}
	${INSTALL_SCRIPT} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif
	@${SED} 's|/usr/local|${PREFIX}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
