# ports collection makefile for:	AliceSoft System 3.5 on X
# Version required:	BETA
# Date created:		24 Oct 1998
# Whom:			FUJISHIMA Satsuki
#
# $Id: Makefile,v 1.6 1998/12/03 15:12:49 flathill Exp $
#

DISTNAME=	xsystem35-BETA-19981227
PKGNAME=	xsystem-3.5-19981227
CATEGORIES=	emulators
MASTER_SITES=	http://www.aist-nara.ac.jp/~masaki-c/private/unitbase/xsys35/down/

#PATCH_SITES=	http://www.aist-nara.ac.jp/~masaki-c/private/unitbase/xsys35/down/
#PATCHFILES=	patch-19981123.diff.gz

MAINTAINER=	k5@respo.or.jp

LIB_DEPENDS+=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

USE_X_PREFIX=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}/src

DOC_FILES=	BUGS ChangeLog FAQ GRFMT.TXT INSTALL README README.midi \
		README.miko THANKS
EXAMPLES=	README.TXT atlach.inf dalk.inf diabo.inf drstop.inf \
		katsumi.inf kichiku.inf miko.inf ningen.inf oudou.inf \
		panyo.inf rance1.inf rance2.inf rance3.inf rance4.inf \
		toushin.inf toushin2.inf zero.inf

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
		${INSTALL_MAN} ${DOC_FILES} ${PREFIX}/share/doc/ja/xsystem35)
	${MKDIR} ${PREFIX}/share/examples/xsystem35
	${INSTALL_DATA} ${WRKSRC}/xsys35rc.sample ${PREFIX}/share/examples/xsystem35
	@(cd ${WRKDIR}/${DISTNAME}/contrib; \
		${INSTALL_SCRIPT} instgame ${PREFIX}/share/examples/xsystem35; \
		${INSTALL_DATA} ${EXAMPLES} ${PREFIX}/share/examples/xsystem35)
.endif
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
