# New ports collection makefile for:	zh-tatter-tools
# Date created:		2005-11-10
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tatter-tools
PORTVERSION=	1.0.6.1
CATEGORIES=	chinese www
MASTER_SITES=	LOCAL/chinsan

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Cute and easy blog tool with Traditional-Chinese(zh_TW.UTF-8)

BROKEN=		Incorrect pkg-plist

USE_PHP=	mysql pcre session xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES

TMPDIR?=	${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${TMPDIR}

.if !defined(TT_URL)
pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define TT_URL to override default of ${TARGETDIR}/${WWWDOCROOT}/'${TT_URL}'."
	@${ECHO_MSG} ""
.endif

WWWDOCROOT?=	www
TT_URL?=	tatter
TT_DIR?=	${WWWDOCROOT}/${TT_URL}
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

pre-install:
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${TT_DIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${TT_DIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${TT_DIR} >> ${PLIST} \
		&& ${ECHO_CMD} @dirrmtry ${WWWDOCROOT} >> ${PLIST}

do-install:
	-${MKDIR} ${TARGETDIR}/${TT_DIR}
	@${CHMOD} 755 ${TARGETDIR}/${TT_DIR}
	@${CP} -R ${WRKSRC}/ ${TARGETDIR}/${TT_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${TARGETDIR}/${TT_DIR}
	@${CHMOD} 777 ${TARGETDIR}/${TT_DIR}/

post-install:
	@${SED} -e 's,%%TT_URL%%,${TT_URL},; s,%%PREFIX%%,${PREFIX},; \
		s,%%TT_DIR%%,${TT_DIR},' ${PKGMESSAGE}

.include <bsd.port.post.mk>
