#
# Ports collection makefile for:	scorched3d
# Date created:				Jan 5, 2003
# Whom:					mdodd
#
# $FreeBSD$

PORTNAME=		scorched3d
PORTVERSION=		0.${SCORCH_VERSION}
PORTREVISION=		3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scorched3d
DISTNAME=		Scorched3D-${SCORCH_VERSION}-src

MAINTAINER=		mdodd@FreeBSD.org
COMMENT=		Scorched is a game based loosely on the classic DOS game

LIB_DEPENDS=		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

USE_SDL=		mixer net sdl
SCORCH_VERSION=		35
WRKSRC=			${WRKDIR}/scorched
GNU_CONFIGURE= 		yes
USE_GL=			yes
USE_GMAKE=		yes
USE_AUTOMAKE_VER=	15
USE_AUTOCONF_VER=	253

AUTOMAKE_ARGS=		--foreign
CONFIGURE_ARGS=		--with-wx-config=${X11BASE}/bin/wxgtk2-2.4-config
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=		ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" \
			AUTOMAKE="${TRUE}" AUTOHEADER="${TRUE}"

pre-configure:
	@cd ${WRKSRC}/scripts && ${PERL} createAMMakefile.pl
	@cd ${WRKSRC} && aclocal

pre-install:
	@mkdir -p ${PREFIX}/games/scorched3d

post-install:
	@ln -fs ${PREFIX}/games/scorched3d/scorched3d ${PREFIX}/bin/scorched3d

.include <bsd.port.mk>
