# New ports collection makefile for:	GSnes9x
# Date created:				18 Jun 2000
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	gsnes9x
PORTVERSION=	3.10
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GSnes9x-${PORTVERSION}

MAINTAINER=	kbyanc@posi.net

RUN_DEPENDS=	snes9x:${PORTSDIR}/emulators/snes9x

GNU_CONFIGURE=	yes
USE_GNOME=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ARGS=	--without-included-gettext \
		--with-esd

.if defined(NOPORTDOCS)

PLIST=	${FILESDIR}/PLIST.nodocs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/GSnes9x ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/gnome \
		  ${PREFIX}/share/gnome/apps \
		  ${PREFIX}/share/gnome/apps/Games \
		  ${PREFIX}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gsnes9x.desktop \
			${PREFIX}/share/gnome/apps/Games/gsnes9x.desktop
	${INSTALL_DATA} ${WRKSRC}/pixmaps/gsnesdefault.png \
			${PREFIX}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/gsnes9x-icon.png \
			${PREFIX}/share/gnome/pixmaps
.else
PLIST=	${FILESDIR}/PLIST.docs
.endif

.include <bsd.port.mk>
