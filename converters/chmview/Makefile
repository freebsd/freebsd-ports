# New ports collection makefile for:	chmview
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	chmview
DISTVERSION=	2.0b4
CATEGORIES=	converters textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	CHMView_${DISTVERSION}

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	Extractor from .chm files

LICENSE=	GPLv2

LIB_DEPENDS=	chm:${PORTSDIR}/misc/chmlib

PROJECTHOST=	ak-various-projects

USE_XZ=		yes
USE_DOS2UNIX=	chmview.c utf8.c utf8.h

WRKSRC=		${WRKDIR}/src
PLIST_FILES=	bin/chmview
MAKE_JOBS_SAFE=	yes

pre-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
