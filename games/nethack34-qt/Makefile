# New ports collection makefile for:	nethack-qt
# Version required:	3.2.2
# Date created:		So   6 Apr 1997 04:25:57 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.6 1997/04/15 01:49:44 asami Exp $
#

DISTNAME=	nethack-3.2.2
PKGNAME=	nethack-3.2.2-qt
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.uu.net/pub/games/nethack/sources/ \
		http://www.uq.edu.au/~cswallis/nhqt/ \
		http://student.uq.edu.au/~s002434/ \
		${MASTER_SITE_GNU}
QT_PATCH=	nhqt0.9.tar.gz
QT_SOUND=	nhs.tar.gz
DISTFILES=	nethack-3.2.2.tar.gz ${QT_PATCH} ${QT_SOUND}

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	auplay:${PORTSDIR}/audio/nas \
		xpmtoppm:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	qt\\.1\\.:${PORTSDIR}/x11/qt \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	auplay:${PORTSDIR}/audio/nas

EXTRACT_ONLY=	nethack-3.2.2.tar.gz
USE_GMAKE=	yes
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6

pre-configure:
	@echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@echo "!!! You cannot install nethack and nethack-qt in parallel !!!"
	@echo "!!! But nethack-qt might read your prior nethack scores   !!!"
	@echo "!!! Don't forget to backup your nethack libdir if it's    !!!"
	@echo "!!! important for you                                     !!!"
	@echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@cd ${WRKSRC}/win; tar xvzf ${DISTDIR}/${QT_PATCH}
	@cd ${WRKSRC}; patch < win/Qt/nhqt.patch
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh
	@cd ${WRKSRC}/src; patch < ${FILESDIR}/src-Makefile.diff
	@cd ${WRKSRC}/src; patch < ${FILESDIR}/src-sounds.c.diff
	@cd ${WRKSRC}; patch < ${FILESDIR}/include-unixconf.h.diff

post-install:
	@cd ${WRKSRC}/doc; chmod 644 *.6
	@cd ${WRKSRC}/doc; PREFIX=${PREFIX} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/nethack
	${CP} ${WRKSRC}/doc/Guidebook.txt ${PREFIX}/share/doc/nethack
.endif
	@cd ${PREFIX}/lib/nethackdir; tar xzf ${DISTDIR}/${QT_SOUND}
	@cd ${PREFIX}/lib/nethackdir; chown games.games *.au .nethackrc
	@cd ${PREFIX}/lib/nethackdir; chmod 444 *.au .nethackrc
	echo "-----------------------"
	echo "post-installation hints
	echo "-----------------------"
	echo "a) Add this to your user environment:"
	echo "   setenv AUDIOSERVER `hostname`:0"
	echo "b) Start the NAS audio server"
	echo "   auvoxware -aa &    # -aa allows any host access"
	echo "c) Copy the example nethackrc file from $FILESDIR to your"
	echo "   login directory:"
	echo "   cp $FILESDIR/sample.nethackrc $HOME/.nethackrc"

.include <bsd.port.mk>
