# New ports collection makefile for:	GSnes9x
# Date created:				18 Jun 2000
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	gsnes9x
PORTVERSION=	3.0
CATEGORIES=	emulators
MASTER_SITES=	http://abulafia.fciencias.unam.mx/~canek/gsnes9x/source/
DISTNAME=	GSnes9x-3.0

MAINTAINER=	kbyanc@posi.net

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		esd.2:${PORTSDIR}/audio/esound
RUN_DEPENDS=	snes9x:${PORTSDIR}/emulators/snes9x

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ARGS=	--without-included-gettext \
		--with-esd

.if defined(NOPORTDOCS)
pre-install:
	${INSTALL_DATA} ${FILESDIR}/PLIST.nodocs ${PKGDIR}/PLIST

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
pre-install:
	${INSTALL_DATA} ${FILESDIR}/PLIST.docs ${PKGDIR}/PLIST
.endif

.include <bsd.port.mk>
