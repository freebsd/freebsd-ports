# ex:ts=8
# New ports collection makefile for:	CyberVRML97
# Date created:			Dec 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cybervrml97
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	graphics
# the master site really is SourceForge, but they only have version 1.1.0
# MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITES=
MASTER_SITE_SUBDIR=	cv97cc
DISTFILES=	cv97r${PORTVERSION:S/.//g}${EXTRACT_SUFX} Makefile
EXTRACT_ONLY=	cv97r${PORTVERSION:S/.//g}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A development library of VRML97/2.0 applications

DIST_SUBDIR=	${PORTNAME}
USE_MESA=	yes
USE_BISON=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/cv97
MAKE_ENV=	CPPFLAGS="${CXXFLAGS} -I${X11BASE}/include -fPIC" \
		LIBS="-L${X11BASE}/lib"
INSTALLS_SHLIB=	yes

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
