# New ports collection makefile for:	nethack-qt
# Version required:	3.2.2
# Date created:		So   6 Apr 1997 04:25:57 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.8 1997/10/04 14:53:07 andreas Exp $
#

DISTNAME=	nethack-3.2.2
PKGNAME=	nethack-3.2.2-qt
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.uu.net/pub/games/nethack/sources/ \
		http://www.uq.edu.au/~cswallis/nhqt/ \
		http://student.uq.edu.au/~s002434/ \
		${MASTER_SITE_GNU}

MAINTAINER=	andreas@FreeBSD.ORG

QT_PATCH=	nhqt0.9.tar.gz
QT_SOUND=	nhs.tar.gz
PATCHFILES=	${QT_PATCH} ${QT_SOUND}

BUILD_DEPENDS=	auplay:${PORTSDIR}/audio/nas \
		xpmtoppm:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	qt\\.1\\.:${PORTSDIR}/x11/qt \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	auplay:${PORTSDIR}/audio/nas

EXTRACT_ONLY=	nethack-3.2.2.tar.gz
USE_GMAKE=	yes
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6

pre-configure:
	@ ${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@ ${ECHO} "!! You cannot install nethack and nethack-qt in parallel !!"
	@ ${ECHO} "!! But nethack-qt might read your prior nethack scores   !!"
	@ ${ECHO} "!! Don't forget to backup your nethack libdir if it's    !!"
	@ ${ECHO} "!! important for you                                     !!"
	@ ${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@ cd ${WRKSRC}/win; tar xvzf ${DISTDIR}/${QT_PATCH}
	@ cd ${WRKSRC}; ${PATCH} < win/Qt/nhqt.patch
	@ cd ${WRKSRC}/sys/unix; ${SH} setup.sh
	@ cd ${WRKSRC}/src; ${PATCH} < ${FILESDIR}/src-Makefile.diff
	@ cd ${WRKSRC}/src; ${PATCH} < ${FILESDIR}/src-sounds.c.diff
	@ cd ${WRKSRC}; ${PATCH} < ${FILESDIR}/include-unixconf.h.diff

post-install:
	@ cd ${WRKSRC}/doc; chmod 644 *.6
	@ cd ${WRKSRC}/doc; PREFIX=${PREFIX} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/nethack
	${CP} ${WRKSRC}/doc/Guidebook.txt ${PREFIX}/share/doc/nethack
.endif
	@ cd ${PREFIX}/lib/nethackdir; tar xzf ${DISTDIR}/${QT_SOUND}
	@ cd ${PREFIX}/lib/nethackdir; chown games.games *.au .nethackrc
	@ cd ${PREFIX}/lib/nethackdir; chmod 444 *.au .nethackrc
	@ ${ECHO}  "-----------------------"
	@ ${ECHO}  "post-installation hints
	@ ${ECHO}  "-----------------------"
	@ ${ECHO}  "a) Add this to your user environment:"
	@ ${ECHO}  "   setenv AUDIOSERVER `hostname`:0"
	@ ${ECHO}  "b) Start the NAS audio server"
	@ ${ECHO}  "   auvoxware -aa &    # -aa allows any host access"
	@ ${ECHO}  "c) Copy the example nethackrc file from $FILESDIR to your"
	@ ${ECHO}  "   login directory:"
	@ ${ECHO}  "   ${CP} $FILESDIR/sample.nethackrc $HOME/.nethackrc"

.include <bsd.port.mk>
