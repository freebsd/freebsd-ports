# New ports collection makefile for:	hanterm3.04
# Date created:		12 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hanterm
PORTVERSION=	3.1.6
PORTREVISION=	3
CATEGORIES=	korean x11
MASTER_SITES=	http://hanterm.org/download/ \
		ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	An xterm hacked for managing Korean languages

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts

CONFLICTS=	ko-hanterm-xf-2.*
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
NO_INSTALL_MANPAGES= yes
ALL_TARGET=	hanterm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hanterm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Hanterm.ad \
		${PREFIX}/lib/X11/app-defaults/Hanterm
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/devel/hanterm.html ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}/
.endif

.include <bsd.port.mk>
