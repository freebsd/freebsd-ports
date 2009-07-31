# New ports collection makefile for:	ko-eterm-0.8.9
# Date created:        8 Jun 1999
# Whom:                Oh Junseon <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	eterm
PORTVERSION=	0.8.9
PORTREVISION=	8
CATEGORIES=	korean x11
MASTER_SITES=	ftp://ftp.holywar.net/pub/FreeBSD/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 terminal emulator based on rxvt/xterm that supports korean

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/local/hmm12.pcf.gz:${PORTSDIR}/korean/hanyangfonts

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_XORG=	x11 xext ice sm xt
USE_GNOME=	imlib
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" LOCALBASE="${LOCALBASE}"
MAN1=		Eterm.1

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/libmej/debug.c ${WRKSRC}/libmej/strings.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes \
		${WRKSRC}/doc/Eterm_reference.html \
		${WRKSRC}/doc/Eterm_reference.html \
		${WRKSRC}/doc/Eterm.tcap \
		${WRKSRC}/doc/Eterm.ti \
		${WRKSRC}/doc/FAQ.html \
			${DOCSDIR}
.endif

.include <bsd.port.mk>
