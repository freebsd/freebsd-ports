# New ports collection makefile for:	makeself
# Version required:	1.4
# Date created:		22 Oct 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	makeself
PKGNAME=	makeself-1.4
CATEGORIES=	archivers
MASTER_SITES=	http://www.lokigames.com/~megastep/makeself/
EXTRACT_SUFX=	.gz.sh

MAINTAINER=	andrews@technologist.com

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/makeself.gz.sh ${PREFIX}/bin/makeself

.include <bsd.port.mk>
