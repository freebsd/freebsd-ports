# ports collection makefile for:	AliceSoft System 3.5 on X
# Version required:	BETA
# Date created:		12 Nov 1998
# Whom:			Seiichirou Hiraoka
#
# $Id$
#

DISTNAME=	xsystem35-BETA-19981024
PKGNAME=	xsystem-3.5-19981024
CATEGORIES=	emulators
MASTER_SITES=	http://ryo1207.aist-nara.ac.jp/unitbase/xsys35/down/

MAINTAINER=	flathill@flathill.gr.jp

BUILD_DEPENDS=	${X11BASE}/lib/libgtk.a:${PORTSDIR}/x11-toolkits/gtk

USE_X_PREFIX=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsystem35 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XSystem35.ad ${PREFIX}/lib/X11/app-defaults
	${MV} ${PREFIX}/lib/X11/app-defaults/XSystem35.ad ${PREFIX}/lib/X11/app-defaults/XSystem35

post-install:
	strip ${PREFIX}/bin/xsystem35
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xsystem35
	@(cd ${WRKDIR}/${DISTNAME}/doc;\
	${INSTALL_MAN} BUGS FAQ GRFMT.TXT INSTALL README THANKS \
		${PREFIX}/share/doc/ja/xsystem35; \
	)
	${MKDIR} ${PREFIX}/share/examples/xsystem35
	@(cd ${WRKDIR}/${DISTNAME}/contrib; \
	${INSTALL_SCRIPT} instgame ${PREFIX}/share/examples/xsystem35; \
	${INSTALL_DATA} README.TXT atlach.inf diabo.inf katsumi.inf kichiku.inf miko.inf ningen.inf oudou.inf panyo.inf rance4.inf toushin2.inf zero.inf \
		${PREFIX}/share/examples/xsystem35; \
	)
	${CAT} ${PKGDIR}/MESSAGE
.endif

.include <bsd.port.mk>
