# New ports collection makefile for:	RealTimeBattle
# Date created:				30 June 2000
# Whom:				Dishanker Rajakulendren <draj@oceanfree.net>
#
# $FreeBSD$
#

PORTNAME=	RealTimeBattle
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.lysator.liu.se/realtimebattle/Download/
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot programming game for UNIX

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk20 lthack
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib

post-extract:
	@${REINPLACE_CMD} -E -e 's/min[[:space:]]*\(/Min(/; s/max[[:space:]]*\(/Max\(/' \
		${WRKSRC}/include/Various.h ${WRKSRC}/src/ArenaBase.cc \
		${WRKSRC}/src/GeometricalObjects.cc ${WRKSRC}/src/Options.cc \
		${WRKSRC}/src/Robot.cc ${WRKSRC}/src/StartTournamentWindow.cc \
		${WRKSRC}/src/StatisticsWindow.cc ${WRKSRC}/src/Various.cc
	@${REINPLACE_CMD} -E -e 's/\(int\*\)/int\*/' ${WRKSRC}/src/ArenaRealTime.cc

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/RealTimeBattle.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
