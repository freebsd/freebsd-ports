# New ports collection makefile for:	eterm
# Date created:        11th December 1998
# Whom:                MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	eterm
PORTVERSION=	0.9
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/Eterm/ \
		ftp://ftp.dti.ad.jp/pub/X/enlightenment/Eterm/ \
		ftp://ftp.kddlabs.co.jp/.10/X11/window_manager/enlightenment/Eterm/ \
		ftp://ftp.sogang.ac.kr/.c/tools/X11/Enlightenment/Eterm/
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER=	nobutaka@nobutaka.com

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lxpg4"
CONFIGURE_ARGS=	--enable-trans=imlib --enable-utmp --enable-multi-charset=kanji \
		--enable-xim --with-theme-update
MAN1=		Eterm.1
INSTALLS_SHLIB=	yes

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/Eterm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm_reference.html ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/doc/Eterm
.endif

.include <bsd.port.mk>
