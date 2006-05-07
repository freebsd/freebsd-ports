# ex:ts=8
# Ports collection makefile for:	multivideo
# Date created:			Oct 18, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	multivideo
PORTVERSION=	0.1.0
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.lis.inpg.fr/pages_perso/bonnaud/multivideo/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image sequence viewer

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
ALL_TARGET=	default

PLIST_FILES=	bin/multivideo

WX_CONFIG=	${X11BASE}/bin/wxgtk2-2.4-config

post-patch:
	@${REINPLACE_CMD} -e 's|g++|\$$\(CXX)|g ; \
		 s|-O2 -g -Wall -W|\$$\(CXXFLAGS\)|g ; \
		 s|[(]CC[)]|\(CXX\)|g ; \
		 s|gcc|\$$\(CXX\)|g ; \
		 s|wx-config|${WX_CONFIG}|g' \
		 	${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multivideo ${PREFIX}/bin

.include <bsd.port.mk>
