#
# Ports collection makefile for:	scorched3d
# Date created:				Jan 5, 2003
# Whom:					mdodd
#
# $FreeBSD$

PORTNAME=		scorched3d
PORTVERSION=		0.${SCORCH_VERSION}${SCORCH_REVISION}
PORTREVISION=		3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scorched3d
DISTNAME=		Scorched3D-${SCORCH_VERSION}-src

MAINTAINER=		guy@device.dyndns.org
COMMENT=		Scorched is a game based loosely on the classic DOS game

BUILD_DEPENDS=		openal-config:${PORTSDIR}/audio/openal
RUN_DEPENDS=		openal-config:${PORTSDIR}/audio/openal
LIB_DEPENDS=		alut.1:${PORTSDIR}/audio/freealut

SCORCH_VERSION=		40.1d

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
.endif
USE_SDL=		mixer net sdl
GNU_CONFIGURE=		yes
USE_GL=			yes
USE_GMAKE=		yes
USE_AUTOTOOLS=	automake:15 autoconf:261
USE_PERL5=	yes
USE_WX=		2.6
WX_CONF_ARGS=	absolute

WRKSRC=			${WRKDIR}/scorched
AUTOMAKE_ARGS=		--foreign
CONFIGURE_ARGS=		--program-prefix='' \
			--prefix=${PREFIX}/games/scorched3d \
			--datadir=${PREFIX}/games/scorched3d
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql
.endif
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=		ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" \
			AUTOMAKE="${TRUE}" AUTOHEADER="${TRUE}"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,g' \
		${WRKSRC}/src/3dsparse/aseFile.tab.cpp \
		${WRKSRC}/src/ode/config.h \
		${WRKSRC}/src/zlib/zutil.h
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${X11BASE},g' \
		${WRKSRC}/configure.ac

pre-configure:
	@cd ${WRKSRC}/scripts && ${PERL} createAMMakefile.pl
	@cd ${WRKSRC} && ${ACLOCAL}

pre-install:
	@${MKDIR} ${PREFIX}/games/scorched3d

.include <bsd.port.post.mk>
