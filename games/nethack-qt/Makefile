# New ports collection makefile for:	nethack-qt
# Version required:	3.2.2
# Date created:		So   6 Apr 1997 04:25:57 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.14 1998/07/27 23:24:44 asami Exp $
#

DISTNAME=	nethack-3.2.2
PKGNAME=	qt-nethack-1.0.1
CATEGORIES=	games
MASTER_SITES=	http://www.troll.no/warwick/nethack/ \
		http://trolls.troll.no/warwick/nethack/ \
		ftp://ftp.troll.no/contrib/ \
		${MASTER_SITE_GNU}
QT_PATCH=	qnethack-3.2.2.1.0.1.src.tar.gz
QT_SOUND=	nhs.tar.gz
DISTFILES=	nethack-3.2.2.tar.gz ${QT_PATCH} ${QT_SOUND}

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	auplay:${PORTSDIR}/audio/nas \
		xpmtoppm:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	qt\\.1\\.40:${PORTSDIR}/x11-toolkits/qt140 \
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
	@ cd ${WRKSRC}/win; tar xzf ${DISTDIR}/${QT_PATCH}
	@ cd ${WRKSRC}; ${PATCH} -s < win/Qt/nhqt.patch
	@ cd ${WRKSRC}/sys/unix; ${SH} setup.sh
	@ cd ${WRKSRC}/src; ${PATCH} -s < ${FILESDIR}/src-Makefile.diff
	@ cd ${WRKSRC}/src; ${PATCH} -s < ${FILESDIR}/src-sounds.c.diff
	@ cd ${WRKSRC}; ${PATCH} -s < ${FILESDIR}/include-unixconf.h.diff

pre-build:
	(cd ${WRKSRC}/util; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} tile2x11 )

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
	@ ${ECHO}  "c) Copy the example nethackrc file from ${FILESDIR} to your"
	@ ${ECHO}  "   login directory:"
	@ ${ECHO}  "   ${CP} ${FILESDIR}/sample.nethackrc ${HOME}/.nethackrc"

.include <bsd.port.mk>
