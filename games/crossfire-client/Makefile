# New ports collection makefile for:	crossfire
# Version required:     0.93.0
# Date created:         So  27 Okt 1996 12:25:55 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.25 1998/09/28 02:06:11 steve Exp $
#

DISTNAME=	crossfire-${MAJ}.${MIN}.${PL}
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.real-time.com/pub/games/crossfire/ \
		ftp://ftp.ifi.uio.no/pub/crossfire/ \
		ftp://ftp.pyramid.com/pub/crossfire/ \
		ftp://ftp.sunet.se/pub/unix/games/crossfire/ \
		ftp://ftp.cs.titech.ac.jp/pub/games/crossfire/
DISTFILES=	${CF_SOURCES} ${CF_DOC} ${CF_MAPS} ${CF_SOUNDS} \
		${CF_ARCH} ${CF_CLSERV}

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	rplay:${PORTSDIR}/audio/rplay
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

EXTRACT_ONLY=	${CF_SOURCES} ${CF_DOC}
USE_PERL5=	yes
USE_IMAKE=	yes
PREFIX=		${LOCALBASE}
MAN6=		crossfire.6 crossedit.6

# Do you want to be able to rebuild documentation after installing the game
# to produce Postscript documentation with colored icons ?! You have to go
# into the workdir and to build everything manually.
# You need TeX to do this ! Please read the README's !
WANT_CF_ARCH=	NO

MAJ=		0
MIN=		94
PL=		3
CF_SOURCES=	crossfire-${MAJ}.${MIN}.${PL}.tar.gz
CF_MAPS=	crossfire-${MAJ}.${MIN}.${PL}.maps.tar.gz
# crossfire doc ready for use
CF_DOC=		crossfire-${MAJ}.${MIN}.${PL}.doc.tar.gz
# no newer sounds available
CF_SOUNDS=	crossfire-${MAJ}.92.7.sounds.tar.gz
.if ${WANT_CF_ARCH} == YES || ${WANT_CF_ARCH} == yes
# only for rebuild of doc
CF_ARCH=	crossfire-${MAJ}.${MIN}.${PL}.arch.tar.gz
.endif
#CF_CLSERV=	eutl.tar.gz		# only for client/server
CFDIR=		${PREFIX}/lib/crossfire	# crossfire base directory

# If you want to re-make playbook and spoiler you need the ARCH
# files and a TeX version with a ,great' amount of max_mem
# (I had to rebuild teTeX, that already is in fact ,BigTeX')
.if ${WANT_CF_ARCH} == YES || ${WANT_CF_ARCH} == yes
post-configure:
	(cd ${CFDIR}; tar -xzf ${DISTDIR}/${CF_ARCH})
.endif

post-install:
	@(cd ${CFDIR}/lib; tar -xzf ${DISTDIR}/${CF_MAPS})
	@(cd ${CFDIR}; tar -xzf ${DISTDIR}/${CF_SOUNDS})
	@${MKDIR} ${PREFIX}/share/doc/crossfire
	@${CP} -r ${WRKDIR}/crossfire-${MAJ}.${MIN}.${PL}-doc/* \
		${PREFIX}/share/doc/crossfire
	@touch ${CFDIR}/lib/bookarch
	@chmod 664 ${CFDIR}/lib/bookarch
	@touch ${CFDIR}/lib/forbid
	@chmod 664 ${CFDIR}/lib/forbid
	@touch ${CFDIR}/lib/players/.keep_me
	@touch ${CFDIR}/lib/unique-items/.keep_me
	@chown -R games.games ${CFDIR}
	@chmod 0664 ${CFDIR}/lib/highscore
	@chown games.games ${PREFIX}/bin/crossfire
	@chmod 6555 ${PREFIX}/bin/crossfire
	${ECHO} "Note: to start crossfire in clientmode"
	${ECHO} "	crossfire -xpm"
	${ECHO} "Note: don't forget to update ${PREFIX}/etc/rplay.conf"
	${ECHO} "	with new sounds in ${CFDIR}/sounds"

.include <bsd.port.mk>
