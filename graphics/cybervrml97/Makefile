# ex:ts=8
# New ports collection makefile for:	CyberVRML97
# Date created:			Dec 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cybervrml97
PORTVERSION=	1.0.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.cyber.koganei.tokyo.jp/vrml/cv97/cv97cc/download/
DISTFILES=	cv97r${PORTVERSION:S/.//g}${EXTRACT_SUFX} Makefile
EXTRACT_ONLY=	cv97r${PORTVERSION:S/.//g}${EXTRACT_SUFX}

MAINTAINER=	3d@FreeBSD.org

DIST_SUBDIR=	${PORTNAME}
USE_MESA=	yes
USE_BISON=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/cv97
MAKE_ENV=	CPPFLAGS="${CXXFLAGS} -I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"
INSTALLS_SHLIB=	yes

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
