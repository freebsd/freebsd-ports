# New ports collection makefile for:	hanterm3.04
# Date created:		12 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hanterm
PORTVERSION=	3.1.6
CATEGORIES=	korean x11
MASTER_SITES=	http://hanterm.org/download/ \
		ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	An xterm hacked for managing Korean languages

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts

CONFLICTS=	ko-hanterm-xf-2.*
USE_IMAKE=	yes
NO_INSTALL_MANPAGES= yes
ALL_TARGET=	hanterm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hanterm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Hanterm.ad \
		${PREFIX}/lib/X11/app-defaults/Hanterm
	${MKDIR} ${PREFIX}/share/doc/hanterm
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/doc/devel/hanterm.html ${PREFIX}/share/doc/hanterm/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/hanterm/
.endif

.include <bsd.port.mk>
