# New ports collection makefile for:	dbskkd-cdb
# Date created:		17 Jun 1999
# Whom:			Makoto Matsushita <matusita@jp.FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	dbskkd-cdb
PORTVERSION=	1.71
CATEGORIES=	japanese
MASTER_SITES=	http://www.ne.jp/asahi/bdx/info/software/
DISTNAME=	${PORTNAME}-${PORTVERSION}dev

MAINTAINER=	matusita@FreeBSD.org
COMMENT=Yet another dictionary server for SKK

BUILD_DEPENDS=	${NONEXISTENT}:${CDBPORTSDIR}:build
RUN_DEPENDS=	${INSTALLEDJISYO}:${PORTSDIR}/japanese/skk-jisyo-cdb

SKKDIR?=	share/skk
SKKJISYO_TYPE?=	L
SKKJISYOCDB?=	/SKK-JISYO.${SKKJISYO_TYPE}.cdb
SERVER_DIR?=	${LOCALBASE}/${SKKDIR}

CDBPORTSDIR=	${PORTSDIR}/databases/cdb
INSTALLEDJISYO=	${LOCALBASE}/${SKKDIR}/SKK-JISYO.${SKKJISYO_TYPE}.cdb
MAKE_ENV+=	SERVER_DIR=${SERVER_DIR} SKKJISYOCDB=${SKKJISYOCDB}
.if !defined(NOPORTDOCS)
PORTDOCS=	${PORTDOCS_FILE} ${PORTDOCS_SH}
PORTDOCS_FILE=	CHANGES LICENSE READMEJP run.example run.log.example
PORTDOCS_SH=	makeskkcdb.sh skktocdbm.sh
.endif

.include <bsd.port.pre.mk>

CDBDIR!=	cd ${CDBPORTSDIR}; ${MAKE} -V WRKSRC

pre-fetch:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Note:"
	@${ECHO_CMD} "    This daemon does chroot(2) to ${SERVER_DIR}, then"
	@${ECHO_CMD} "    use ${SKKJISYOCDB} as a dictionary file."
	@${ECHO_CMD} "    Please set SERVER_DIR/SKKJISYOCDB variables if you don't like much."
	@${ECHO_CMD} ""

post-patch:
.for f in READMEJP copyfromcdb.sh
	${SED} -e "s!%%PREFIX%%!${PREFIX}!g" -e "s!%%SKKDIR%%!${SKKDIR}!g" -e "s!%%JISYONAME%%!SKK-JISYO.${SKKJISYO_TYPE}!g" -e "s!%%CDBDIR%%!${CDBDIR}!g" < ${WRKSRC}/${f} > ${WRKSRC}/.tmp
	${MV} -f ${WRKSRC}/.tmp ${WRKSRC}/${f}
.endfor
	${CHMOD} +x ${WRKSRC}/copyfromcdb.sh

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
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Note for inetd users:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Add following line to /etc/inetd.conf"
	@${ECHO_CMD} "   skkserv stream tcp nowait root ${PREFIX}/libexec/dbskkd-cdb dbskkd-cdb"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "If dbskkd-cdb 1.01 was running, please update your /etc/inetd.conf line."
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
