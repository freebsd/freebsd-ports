# New ports collection makefile for:	makeself
# Date created:		22 Oct 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	makeself
PORTVERSION=	2.1.1
CATEGORIES=	archivers
MASTER_SITES=	http://www.megastep.org/makeself/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A neat script to make self-extracting archives

WRKSRC=		${WRKDIR}/${DISTNAME}-${PORTVERSION}
EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS= --nox11 --target ${WRKSRC}
NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/makeself.sh ${PREFIX}/bin/makeself

.include <bsd.port.mk>
