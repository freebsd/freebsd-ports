# Created by: Makoto Matsushita <matusita@jp.FreeBSD.ORG>
# $FreeBSD$

PORTNAME=	dbskkd-cdb
PORTVERSION=	3.00
#PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	GH

MAINTAINER=	kenji@k2r.org
COMMENT=	SKK dictionary server based on cdb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libcdb.a:databases/tinycdb
RUN_DEPENDS=	${SKKJISYOCDB}:japanese/skk-jisyo-cdb

USE_GITHUB=	yes
GH_ACCOUNT=	jj1bdx
GH_TAGNAME=	3.00
MAKE_ENV=	LOCALBASE="${LOCALBASE}" \
		SKKJISYOCDB="${SKKJISYOCDB}"
PLIST_FILES=	libexec/dbskkd-cdb
SUB_FILES=	pkg-message
PORTDOCS=	${PORTDOCS_FILE} ${PORTDOCS_SH}

SKKDIR?=	share/skk
SKKJISYO_TYPE?=	L
SKKJISYOCDB?=	${LOCALBASE}/${SKKDIR}/SKK-JISYO.${SKKJISYO_TYPE}.cdb
PORTDOCS_FILE=	CHANGES.md LICENSE README.md READMEJP.md \
		examples.md skk-server-protocol.md
PORTDOCS_SH=	makeskkcdb.sh skktocdbm.sh

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

post-patch:
.for f in READMEJP.md makeskkcdb.sh
	${REINPLACE_CMD} -e "s!%%PREFIX%%!${PREFIX}!g" \
		-e "s!%%SKKDIR%%!${SKKDIR}!g" \
		-e "s!%%JISYONAME%%!SKK-JISYO.${SKKJISYO_TYPE}!g" ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbskkd-cdb ${STAGEDIR}${PREFIX}/libexec

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS_FILE:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${PORTDOCS_SH:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
