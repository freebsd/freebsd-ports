# ex:ts=8
# Ports collection makefile for:	multivideo
# Date created:			Oct 18, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	multivideo
PORTVERSION=	0.1.0
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://www.lis.inpg.fr/pages_perso/bonnaud/multivideo/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image sequence viewer

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_WX=		2.4
ALL_TARGET=	default

PLIST_FILES=	bin/multivideo

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
