# New ports collection makefile for:	crossfire
# Version required:     0.93.0
# Date created:         So  27 Okt 1996 12:25:55 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.16 1997/07/18 05:04:10 asami Exp $
#

DISTNAME=	crossfire-0.93.0
CATEGORIES=	games
MASTER_SITES=	ftp://ra.pyramid.com/pub/crossfire/ \
		ftp://ftp.ifi.uio.no/pub/crossfire/ \
		ftp://ftp.real-time.com/pub/games/crossfire/ \
		ftp://ftp.sunet.se:/pub/unix/games/crossfire/ \
		ftp://ftp.cs.titech.ac.jp:/pub/games/crossfire/
DISTFILES=	${CF_SOURCES} ${CF_DOC} ${CF_MAPS} ${CF_SOUNDS} \
		${CF_ARCH} ${CF_CLSERV}

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	rplay:${PORTSDIR}/audio/rplay
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	perl5.00401:${PORTSDIR}/lang/perl5

EXTRACT_ONLY=	${CF_SOURCES} ${CF_DOC}
USE_IMAKE=	yes
PREFIX=		${LOCALBASE}		# don't use /usr/X11R6

# Do you want to be able to rebuild documentation after installing the game
# to produce Postscript documentation with colored icons ?! You have to go 
# into the workdir and to build everything manually. 
# You need TeX to do this ! Please read the README's !
WANT_CF_ARCH=	NO

CF_SOURCES=	crossfire-0.93.0.tar.gz
CF_MAPS=	crossfire-0.93.0.maps.tar.gz
CF_DOC=		crossfire-0.93.0.doc.tar.gz	# crossfire doc ready for use
CF_SOUNDS=	crossfire-0.92.7.sounds.tar.gz	# no newer sounds available
.if ${WANT_CF_ARCH} == YES || ${WANT_CF_ARCH} == yes
CF_ARCH=	crossfire-0.93.5.arch.tar.gz	# only for rebuild of doc
.endif
#CF_CLSERV=	eutl.tar.gz			# only for client/server
CFDIR=		${PREFIX}/crossfire	# crossfire base directory

# If you want to re-make playbook and spoiler you need the ARCH
# files and a TeX version with a ,great' amount of max_mem 
# (I had to rebuild teTeX, that already is in fact ,BigTeX')
.if ${WANT_CF_ARCH} == YES || ${WANT_CF_ARCH} == yes
post-configure:
	(cd ${WRKSRC}/lib; tar -xzf ${DISTDIR}/${CF_ARCH})
.endif

post-install:
	@(cd ${CFDIR}/lib; tar -xzf ${DISTDIR}/${CF_MAPS})
	@(cd ${CFDIR}; tar -xzf ${DISTDIR}/${CF_SOUNDS})
	@${MKDIR} ${CFDIR}/doc
	@${CP} -r ${WRKDIR}/crossfire-0.93.0-doc/* ${CFDIR}/doc
	@touch ${PREFIX}/crossfire/lib/bookarch
	@chmod 664 ${PREFIX}/crossfire/lib/bookarch
	@touch ${PREFIX}/crossfire/lib/forbid
	@chmod 664 ${PREFIX}/crossfire/lib/forbid
	@touch ${PREFIX}/crossfire/lib/players/.keep_me  
	@touch ${PREFIX}/crossfire/lib/unique-items/.keep_me  
	@/usr/sbin/chown -R games.games ${CFDIR}
	@chmod 0664 ${PREFIX}/crossfire/lib/highscore
	@/usr/sbin/chown games.games ${PREFIX}/bin/crossfire
	@chmod 6555 ${PREFIX}/bin/crossfire

.include <bsd.port.mk>
