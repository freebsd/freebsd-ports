# ex:ts=8
# New ports collection makefile for:	p65
# Date created:			Dec 17, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	p65
PORTVERSION=	1.0a
CATEGORIES=	devel
MASTER_SITES=	http://hkn.berkeley.edu/~mcmartin/P65/pl/
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}
USE_PERL5=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
