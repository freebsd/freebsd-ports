# New ports collection makefile for:   phpMinAdmin
# Date created:			28 August 2008
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	phpminadmin
PORTVERSION=	1.7.0
CATEGORIES=	databases www
MASTER_SITES=	SF
DISTNAME=	phpMinAdmin-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A MySQL Management Tool Written in PHP

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PHP=	mysql session
SUB_FILES=	pkg-message

MM_SCRIPTS_FILES=	_compile.php _lang.php \
		abstraction.inc.php auth.inc.php call.inc.php \
		connect.inc.php create.inc.php createv.inc.php \
		database.inc.php design.inc.php download.inc.php \
		dump.inc.php edit.inc.php editing.inc.php \
		export.inc.php foreign.inc.php functions.inc.php \
		index.php indexes.inc.php lang.inc.php \
		privileges.inc.php procedure.inc.php processlist.inc.php \
		schema.inc.php select.inc.php sql.inc.php \
		table.inc.php trigger.inc.php user.inc.php \
		view.inc.php
MM_DATA_FILES=	arrow.gif default.css down.gif \
		favicon.ico minus.gif plus.gif \
		todo.txt up.gif
MM_DIR=		lang

do-install:
	${MKDIR} ${WWWDIR}
.for i in ${MM_SCRIPTS_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${WWWDIR}
.endfor
.for i in ${MM_DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${WWWDIR}
.endfor
.for i in ${MM_DIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${WWWDIR}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
