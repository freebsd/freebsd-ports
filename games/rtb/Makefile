# New ports collection makefile for:	RealTimeBattle
# Date created:				30 June 2000
# Whom:				Dishanker Rajakulendren <draj@oceanfree.net>
#
# $FreeBSD$
#

PORTNAME=	RealTimeBattle
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTNAME=	${PORTNAME}-${PORTVERSION}-Ext

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot programming game for UNIX

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk20
USE_GCC=	3.4
USE_PERL5=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-rtb-dir=${PREFIX}/lib/${PORTNAME}

CXXFLAGS+=	-fpermissive

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib -lintl

post-patch:
.for file in include/Various.h src/ArenaBase.cc src/GeometricalObjects.cc \
	src/Options.cc src/Robot.cc src/StartTournamentWindow.cc \
	src/StatisticsWindow.cc src/Various.cc
	@${REINPLACE_CMD} -E -e 's|min[[:space:]]*\(|Min(|g ; \
		 s|max[[:space:]]*\(|Max\(|g' ${WRKSRC}/${file}
.endfor
.for file in src/ArenaRealTime.cc
	@${REINPLACE_CMD} -E -e 's|\(int\*\)|int\*|g' ${WRKSRC}/${file}
.endfor
.for file in rtb-team-framework/createrobot.sh \
	rtb-team-framework/createrobotconf.sh
	@${REINPLACE_CMD} -e 's| sed| gsed|g' ${WRKSRC}/${file}
.endfor
.for file in Makefile.in
	@${REINPLACE_CMD} -e 's|intl Documentation||g' ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog EXTRAROBOTS.README NEWS README TODO \
	Documentation/RealTimeBattle-1.html \
	Documentation/RealTimeBattle-2.html \
	Documentation/RealTimeBattle-3.html \
	Documentation/RealTimeBattle-4.html \
	Documentation/RealTimeBattle-5.html \
	Documentation/RealTimeBattle-6.html \
	Documentation/RealTimeBattle.html \
	Documentation/next.gif Documentation/prev.gif Documentation/toc.gif \
	Documentation/next.png Documentation/prev.png Documentation/toc.png \
	Documentation/RealTimeBattle.dvi \
	Documentation/RealTimeBattle.sgml \
	Documentation/RealTimeBattle.txt \
	Documentation/RTB-Team-Framework-Tutorial.tar.gz
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
