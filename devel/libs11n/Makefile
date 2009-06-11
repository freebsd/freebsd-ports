# New ports collection makefile for:    libs11n
# Date created:         23 Nov 2005
# Whom:                 aaron@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libs11n
PORTVERSION=	1.2.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	s11n
DISTNAME=	${PORTNAME}-${PORTVERSION}-nobuildfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library for easily serializing a wide variety of objects

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_ZIP=	yes
USE_LDCONFIG=	yes

post-extract:
	@${CP} ${PATCHDIR}/Makefile.bsd ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${PREFIX}/include/s11n.net
	${MKDIR} ${PREFIX}/include/s11n.net/s11n
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/io
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/nodeutil
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/plugin
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/proxy
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/proxy/pod
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/proxy/std

.include <bsd.port.mk>
