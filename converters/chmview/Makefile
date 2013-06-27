# Created by: Alex Semenyaka <alex@rinet.ru>
# $FreeBSD$

PORTNAME=	chmview
PORTVERSION=	2.0b4
PORTREVISION=	1
CATEGORIES=	converters textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ak@FreeBSD.org
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
