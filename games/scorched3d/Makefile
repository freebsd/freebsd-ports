#
# Ports collection makefile for:	scorched3d
# Date created:				Jan 5, 2003
# Whom:					mdodd
#
# $FreeBSD$

PORTNAME=		scorched3d
PORTVERSION=		0.${SCORCH_VERSION}${SCORCH_REVISION}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scorched3d
DISTNAME=		Scorched3D-${SCORCH_VERSION}-src

MAINTAINER=		guy@device.dyndns.org
COMMENT=		Scorched is a game based loosely on the classic DOS game

BUILD_DEPENDS=		${X11BASE}/include/wx-2.6/wx/wx.h:${PORTSDIR}/x11-toolkits/wxgtk26-common \
			wxgtk2-2.6-config:${PORTSDIR}/x11-toolkits/wxgtk26 \
			openal-config:${PORTSDIR}/audio/openal
RUN_DEPENDS=		${X11BASE}/include/wx-2.6/wx/wx.h:${PORTSDIR}/x11-toolkits/wxgtk26-common \
			wxgtk2-2.6-config:${PORTSDIR}/x11-toolkits/wxgtk26 \
			openal-config:${PORTSDIR}/audio/openal

SCORCH_VERSION=		39.1

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
.endif
USE_SDL=		mixer net sdl
GNU_CONFIGURE=		yes
USE_GL=			yes
USE_GMAKE=		yes
USE_AUTOMAKE_VER=	15
USE_AUTOCONF_VER=	253

WRKSRC=			${WRKDIR}/scorched
AUTOMAKE_ARGS=		--foreign
CONFIGURE_ARGS=		--program-prefix='' \
			--prefix=${PREFIX}/games/scorched3d \
			--datadir=${PREFIX}/games/scorched3d \
			--with-wx-config=${X11BASE}/bin/wxgtk2-2.6-config
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql
.endif
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=		ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" \
			AUTOMAKE="${TRUE}" AUTOHEADER="${TRUE}"

.include <bsd.port.pre.mk>

pre-configure:
	@cd ${WRKSRC}/scripts && ${PERL} createAMMakefile.pl
	@cd ${WRKSRC} && ${ACLOCAL}

pre-install:
	@${MKDIR} ${PREFIX}/games/scorched3d

.include <bsd.port.post.mk>
