# ex:ts=8
# Ports collection makefile for:	multivideo
# Date created:			Oct 18, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	multivideo
PORTVERSION=	0.1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.lis.inpg.fr/scientifique/bonnaud/multivideo/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An image sequence viewer

LIB_DEPENDS=	wx_gtk-2.2.2:${PORTSDIR}/x11-toolkits/wxgtk

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
ALL_TARGET=	default

post-patch:
	@${REINPLACE_CMD} -e 's|g++|\$$\(CXX)|g ; \
		 s|-O2 -g -Wall -W|\$$\(CXXFLAGS\)|g ; \
		 s|[(]CC[)]|\(CXX\)|g ; \
		 s|gcc|\$$\(CXX\)|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multivideo ${PREFIX}/bin

.include <bsd.port.mk>
