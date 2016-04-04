# Created by: Makoto Matsushita <matusita@jp.FreeBSD.ORG>
# $FreeBSD$

PORTNAME=	dbskkd-cdb
PORTVERSION=	2.00
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another dictionary server for SKK

BUILD_DEPENDS=	${LOCALBASE}/lib/libcdb.a:databases/tinycdb
RUN_DEPENDS=	${SKKJISYOCDB}:japanese/skk-jisyo-cdb

PLIST_FILES=	libexec/dbskkd-cdb
SUB_FILES=	pkg-message

SKKDIR?=	share/skk
SKKJISYO_TYPE?=	L
SKKJISYOCDB?=	${LOCALBASE}/${SKKDIR}/SKK-JISYO.${SKKJISYO_TYPE}.cdb

MAKE_ENV+=	LOCALBASE="${LOCALBASE}"
MAKE_ENV+=	SKKJISYOCDB="${SKKJISYOCDB}"

PORTDOCS=	${PORTDOCS_FILE} ${PORTDOCS_SH}
PORTDOCS_FILE=	CHANGES LICENSE READMEJP \
		example-daemontools.txt example-inetd.txt
PORTDOCS_SH=	makeskkcdb.sh skktocdbm.sh

OPTIONS_DEFINE=	DOCS

post-patch:
.for f in READMEJP makeskkcdb.sh
	${REINPLACE_CMD} -e "s!%%PREFIX%%!${PREFIX}!g" \
		-e "s!%%SKKDIR%%!${SKKDIR}!g" \
		-e "s!%%JISYONAME%%!SKK-JISYO.${SKKJISYO_TYPE}!g" ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbskkd-cdb ${STAGEDIR}${PREFIX}/libexec
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS_FILE:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${PORTDOCS_SH:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
