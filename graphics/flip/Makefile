# ex:ts=8
# Ports collection makefile for:	flip
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flip
PORTVERSION=	2.2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.reptilelabour.com/software/files/flip/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	mpeg_encode:${PORTSDIR}/graphics/mpeg_encode

USE_QT_VER=	2
WRKSRC=		${WRKDIR}/${DISTNAME:R}
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	MOC="${MOC}" QTDIR="${X11BASE}"

post-patch:
	@${PERL} -pi -e "s,^CC,#CC,g ; s,^CXX,#CXX,g ; \
		s,^CFLAGS,#CFLAGS,g ; s,^CXXFLAGS,#CXXFLAGS,g ; \
		s,^MOC,#MOC,g ; s,lqt,lqt2,g ; \
		s,/usr/X11R6,${X11BASE},g ; \
		s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Config.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flip ${PREFIX}/bin

.include <bsd.port.mk>
