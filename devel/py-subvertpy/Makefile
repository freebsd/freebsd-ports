# Ports collection makefile for:	subvertpy
# Date created:				9 August 2010
# Whom:					Carlo Strub (c-s@c-s.li)
#
# $FreeBSD$
#

PORTNAME=	subvertpy
PORTVERSION=	0.7.3.1
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/52613338/ \
		http://samba.org/~jelmer/subvertpy/ \
		http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	c-s@c-s.li
COMMENT=	Python bindings for subversion

BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	subvertpy

.include <bsd.port.mk>
