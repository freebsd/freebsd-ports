# New ports collection makefile for:   crystal
# Date created:        Thu Feb 21 18:44:14 CST 2002
# Whom:                Kyle Martin
#
# $FreeBSD$
#

PORTNAME=	crystal
PORTVERSION=	0.94
CATEGORIES=	devel
MASTER_SITES=	ftp://sunsite.dk/projects/crystal/cs094/source/
DISTNAME=	cs94_002

MAINTAINER=	mkm@ieee.org

BROKEN=		"Does not build"

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/CS

pre-build:
	cd ${WRKSRC}; ${GMAKE} freebsd

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|' \
		${WRKSRC}/plugins/cscript/cspython/cspython.mak
	@${FIND} ${WRKSRC} -name "*.mak" | ${XARGS} ${PERL} -pi -e \
		's|-O6|${PTHREAD_CFLAGS}|; s|/usr/local|${LOCALBASE}|; \
		s|INSTALL_DIR = ${LOCALBASE}/crystal|INSTALL_DIR = ${PREFIX}/crystal|'

.include <bsd.port.mk>
