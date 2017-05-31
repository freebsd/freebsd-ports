# New ports collection makefile for:		bashdb
# Date created:					2013-01-26
# Whom:						rocky
#
# $FreeBSD$

PORTNAME=	bashdb
PORTVERSION=	0.8
CATEGORIES=	devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=bashdb/code/
DISTNAME=	bashdb-4.2-${PORTVERSION}

MAINTAINER=	rocky@gnu.org
COMMENT=	Bash debugger

LICENSE=	GPLv2
LICENSE_FILE=    ${WRKSRC}/COPYING

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
