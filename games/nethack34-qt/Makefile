# New ports collection makefile for:	nethack-qt
# Date created:		So   6 Apr 1997 04:25:57 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	qt-nethack
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://trolls.troll.no/warwick/nethack/ \
		ftp://ftp.troll.no/contrib/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	nethack
DISTNAME=	nethack-3.2.2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${QT_PATCH} ${QT_SOUND}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	auplay:${PORTSDIR}/audio/nas \
		xpmtoppm:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS=	auplay:${PORTSDIR}/audio/nas

QT_PATCH=	qnethack-3.2.2.1.0.1.src.tar.gz
QT_SOUND=	nhs.tar.gz
EXTRACT_ONLY=	nethack-3.2.2.tar.gz

USE_QT_VER=	1
USE_XPM=	yes
USE_GMAKE=	yes
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6

BROKEN=		"Compiler error"

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
	@ cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@ cd ${WRKSRC}/doc; PREFIX=${PREFIX} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/nethack
	${CP} ${WRKSRC}/doc/Guidebook.txt ${PREFIX}/share/doc/nethack
.endif
	@ cd ${PREFIX}/lib/nethackdir; tar xzf ${DISTDIR}/${QT_SOUND}
	@ cd ${PREFIX}/lib/nethackdir; ${CHOWN} root.games *.au .nethackrc
	@ cd ${PREFIX}/lib/nethackdir; ${CHMOD} 444 *.au .nethackrc
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
