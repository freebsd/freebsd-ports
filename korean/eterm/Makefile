# New ports collection makefile for:	ko-eterm-0.8.9
# Date created:        8 Jun 1999
# Whom:                Oh Junseon <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	eterm
PORTVERSION=	0.8.9
CATEGORIES=	korean x11
MASTER_SITES=	ftp://ftp.eterm.org/pub/Eterm/ \
		ftp://ftp.holywar.net/pub/FreeBSD/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/ \
		http://www.tcserv.com/archive/E/ \
		http://eterm.is.nontoxic.org/download/ \
		http://www.tcserv.com/archive/E/old/
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER=	hollywar@mail.holywar.net

RUN_DEPENDS=    ${PREFIX}/lib/X11/fonts/local/hmm12.pcf.gz:${PORTSDIR}/korean/hanyangfonts

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_IMLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=  LIBS="-L${LOCALBASE}/lib -lxpg4"
MAN1=		Eterm.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm_reference.html ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/FAQ.html ${PREFIX}/share/doc/Eterm
.endif

.include <bsd.port.mk>
