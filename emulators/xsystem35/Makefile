# ports collection makefile for:	AliceSoft System 3.5 on X
# Version required:	BETA
# Date created:		24 Oct 1998
# Whom:			FUJISHIMA Satsuki
#
# $Id: Makefile,v 1.8 1999/01/10 18:31:20 steve Exp $
#

DISTNAME=	xsystem35-1.0
PKGNAME=	xsystem-3.5-1.0
CATEGORIES=	emulators
MASTER_SITES=	http://www.aist-nara.ac.jp/~masaki-c/private/unitbase/xsys35/down/

#PATCH_SITES=	http://www.aist-nara.ac.jp/~masaki-c/private/unitbase/xsys35/down/
#PATCHFILES=	patch-19981123.diff.gz

MAINTAINER=	k5@respo.or.jp

LIB_DEPENDS+=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

USE_IMAKE=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}/src

DOC_FILES=	BUGS ChangeLog FAQ GRFMT.TXT INSTALL README README.midi \
		README.miko THANKS TODO
EXAMPLES=	README.TXT atlach.inf dalk.inf diabo.inf drstop.inf \
		katsumi.inf kichiku.inf miko.inf ningen.inf oudou.inf \
		panyo.inf rance1.inf rance2.inf rance3.inf rance4.inf \
		toushin.inf toushin2.inf zero.inf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsystem35 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../contrib/instgame ${PREFIX}/bin

post-install:
	strip ${PREFIX}/bin/xsystem35
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xsystem35
	@(cd ${WRKSRC}/../doc;\
		${INSTALL_MAN} ${DOC_FILES} ${PREFIX}/share/doc/ja/xsystem35)
	${MKDIR} ${PREFIX}/share/examples/xsystem35
	${INSTALL_DATA} ${WRKSRC}/xsys35rc.sample ${PREFIX}/share/examples/xsystem35
	@(cd ${WRKSRC}/../contrib; \
		${INSTALL_DATA} ${EXAMPLES} ${PREFIX}/share/examples/xsystem35)
.endif
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
