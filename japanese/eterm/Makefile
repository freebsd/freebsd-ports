# New ports collection makefile for:	eterm
# Version required:    0.8.7
# Date created:        11th December 1998
# Whom:                MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $Id: Makefile,v 1.1.1.1 1998/12/16 18:48:20 sada Exp $
#

DISTNAME=	Eterm-0.8.7
PKGNAME=	ja-eterm-0.8.7
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/Eterm/ \
		http://www.tcserv.com/archive/E/ \
		http://www.tcserv.com/archive/E/old/

MAINTAINER=	nobutaka@nobutaka.com

LIB_DEPENDS=	Imlib.2:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=		Eterm.1

post-install:
.ifndef NOPORTDOCS
	@${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.help ${PREFIX}/share/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ref ${PREFIX}/share/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/FAQ.html ${PREFIX}/share/Eterm
	@${INSTALL_SCRIPT} ${WRKSRC}/doc/colortest.sh ${PREFIX}/share/Eterm
	@${INSTALL_SCRIPT} ${WRKSRC}/doc/menu_cmd ${PREFIX}/share/Eterm
.endif

.include <bsd.port.mk>
