# New ports collection makefile for:	scons
# Date created:				16 December 2001
# Whom:					Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	scons
PORTVERSION=	0.96.90
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	A build tool alternative to make

MAN1=		scons.1

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - 2>/dev/null || ${TRUE}

post-install:
	${INSTALL_MAN} ${WRKSRC}/scons.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
