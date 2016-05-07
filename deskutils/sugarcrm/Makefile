# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	sugarcrm
PORTVERSION=	6.5.23
CATEGORIES=	deskutils www
MASTER_SITES=	SF/${PORTNAME}/1%20-%20SugarCRM%206.5.X/SugarCommunityEdition-6.5.X
DISTNAME=	SugarCE-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Web based customer relationship management suite

BROKEN_powerpc64=	Does not build

USES=		zip
USE_PHP=	gd mysqli session pcre xml zlib mbstring curl imap spl posix \
		json ctype zip tokenizer
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SugarCE-Full-${PORTVERSION}

PLIST=		${WRKDIR}/plist
SUGARDIR=	www/sugarcrm

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES+=	pkg-message pkg-install

pre-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${SUGARDIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${SUGARDIR}?g" >> ${PLIST}
	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}/${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/

.include <bsd.port.mk>
