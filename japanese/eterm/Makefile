# New ports collection makefile for:	eterm
# Version required:    0.8.10
# Date created:        11th December 1998
# Whom:                MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

DISTNAME=	Eterm-0.8.10
PKGNAME=	ja-eterm-0.8.10
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://eterm.sourceforge.net/pub/eterm/ \
		ftp://ftp.enlightenment.org/pub/enlightenment/Eterm/ \
		ftp://ftp.themes.org/pub/enlightenment/eterm/ \
		ftp://ftp.dti.ad.jp/pub/X/Eterm/

MAINTAINER=	nobutaka@nobutaka.com

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lxpg4"
MAN1=		Eterm.1

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
