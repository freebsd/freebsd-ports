# Ports collection makefile for:	subvertpy
# Date created:				9 August 2010
# Whom:					Carlo Strub (c-s@c-s.li)
#
# $FreeBSD$
#

PORTNAME=	subvertpy
PORTVERSION=	0.8.8
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/81204254/ \
		http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Python bindings for subversion

LICENSE=	GPLv2

BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	subvertpy

#post-patch:
#		@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
