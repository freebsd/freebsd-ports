# New ports collection makefile for:	ko-eterm-0.8.9
# Date created:        8 Jun 1999
# Whom:                Oh Junseon <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	eterm
PORTVERSION=	0.8.9
PORTREVISION=	1
CATEGORIES=	korean x11
MASTER_SITES=	ftp://ftp.holywar.net/pub/FreeBSD/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER=	hollywar@mail.holywar.net
COMMENT=	X11 terminal emulator based on rxvt/xterm that supports korean

RUN_DEPENDS=	${PREFIX}/lib/X11/fonts/local/hmm12.pcf.gz:${PORTSDIR}/korean/hanyangfonts

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	imlib
USE_INC_LIBTOOL_VER=13
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" LOCALBASE="${LOCALBASE}"
MAN1=		Eterm.1

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/libmej/debug.c ${WRKSRC}/libmej/strings.c

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
