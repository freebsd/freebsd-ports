# ports collection makefile for:	AliceSoft System 3.5 on X
# Version required:	BETA
# Date created:		24 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $Id: Makefile,v 1.2 1998/11/19 16:06:41 flathill Exp $
#

DISTNAME=	xsystem35-BETA-19981114
PKGNAME=	xsystem-3.5-19981114
CATEGORIES=	emulators
MASTER_SITES=	http://ryo1207.aist-nara.ac.jp/unitbase/xsys35/down/

MAINTAINER=	flathill@FreeBSD.ORG

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

USE_X_PREFIX=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}/src

pre-build:
.if !defined(CDROM_NO_TRKIND)
	@${ECHO_MSG} "if your CD-ROM drive complains like 'CDIOCPLAYTRACKS: Invalid argument'"
	@${ECHO_MSG} "at playing CDDA, try: make CDROM_NO_TRKIND=yes"
	@${ECHO_MSG} "this may workaround problem."
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsystem35 ${PREFIX}/bin

post-install:
	strip ${PREFIX}/bin/xsystem35
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xsystem35
	@(cd ${WRKDIR}/${DISTNAME}/doc;\
	${INSTALL_MAN} BUGS FAQ GRFMT.TXT INSTALL README THANKS \
		${PREFIX}/share/doc/ja/xsystem35; \
	)
	${MKDIR} ${PREFIX}/share/examples/xsystem35
	${INSTALL_DATA} ${WRKSRC}/xsys35rc.sample ${PREFIX}/share/examples/xsystem35
	@(cd ${WRKDIR}/${DISTNAME}/contrib; \
	${INSTALL_SCRIPT} instgame ${PREFIX}/share/examples/xsystem35; \
	${INSTALL_DATA} README.TXT atlach.inf diabo.inf katsumi.inf kichiku.inf miko.inf ningen.inf oudou.inf panyo.inf rance4.inf toushin2.inf zero.inf \
		${PREFIX}/share/examples/xsystem35; \
	)
.endif
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
