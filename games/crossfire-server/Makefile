# New ports collection makefile for:	crossfire
# Version required:     0.92.8
# Date created:         So  27 Okt 1996 12:25:55 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id:
#

DISTNAME=	crossfire-0.92.8
CATEGORIES+=	games
MASTER_SITES=	ftp://ra.pyramid.com/pub/crossfire/ \
		ftp://ftp.ifi.uio.no/pub/crossfire/ \
		ftp://ftp.real-time.com/pub/games/crossfire/ \
		ftp://yoyo.cc.monash.edu.au/pub/crossfire/ \
		ftp://ftp.cs.city.ac.uk:/pub/games/crossfire/ \
		ftp://ftp.sunet.se:/pub/unix/games/crossfire/ \
		ftp://ftp.cs.titech.ac.jp:/pub/games/crossfire/

MAINTAINER=	andreas@klemm.gtn.com

# Do you want to be able to rebuild documentation after installing the game
# to produce Postscript documentation with colored icons ?! You have to go 
# into the workdir and to build everything manually. 
# You need TeX to do this ! Please read the README's !
WANT_CF_ARCH=	NO

CF_SOURCES=	crossfire-0.92.8.tar.gz
CF_MAPS=	crossfire-0.92.8.maps.tar.gz
CF_SOUNDS=	crossfire-0.92.7.sounds.tar.gz	# no newer sounds available
CF_DOC=		crossfire-0.92.8.doc.tar.gz	# crossfire doc ready for use
.if ${WANT_CF_ARCH} == YES || ${WANT_CF_ARCH} == yes
CF_ARCH=	crossfire-0.92.8.arch.tar.gz	# only for rebuild of doc
.endif
#CF_CLSERV=	eutl.tar.gz			# only for client/server

DISTFILES=	${CF_SOURCES} ${CF_DOC} ${CF_MAPS} ${CF_SOUNDS} \
		${CF_ARCH} ${CF_CLSERV}

EXTRACT_ONLY=	${CF_SOURCES} ${CF_DOC}

BUILD_DEPENDS=	rplay:${PORTSDIR}/audio/rplay
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

USE_IMAKE=	yes
PREFIX=		/usr/local		# don't use /usr/X11R6
CFDIR=		${PREFIX}/crossfire	# crossfire base directory

# If you want to re-make playbook and spoiler you need the ARCH
# files and a TeX version with a ,great' amount of max_mem 
# (I had to rebuild teTeX, that already is in fact ,BigTeX')
.if ${WANT_CF_ARCH} == YES || ${WANT_CF_ARCH} == yes
post-configure:
	(cd ${WRKSRC}/lib; tar -xzf ${DISTDIR}/${CF_ARCH})
.endif

post-install:
	(cd ${CFDIR}/lib; tar -xzf ${DISTDIR}/${CF_MAPS})
	(cd ${CFDIR}; tar -xzf ${DISTDIR}/${CF_SOUNDS})
	mkdir -p ${CFDIR}/doc
	cp -r ${WRKDIR}/crossfire-0.92.8-doc/* ${CFDIR}/doc
	touch ${PREFIX}/crossfire/lib/bookarch
	chmod 664 ${PREFIX}/crossfire/lib/bookarch
	chown -R games.games ${CFDIR}
	chmod 0664 ${PREFIX}/crossfire/lib/highscore
	chown games.games ${PREFIX}/bin/crossfire
	chmod 6555 ${PREFIX}/bin/crossfire
	@echo ""
	@echo ""
	@echo "======================================================"
	@echo "===== ATTENTION BEFORE PLAYING ======================="
	@echo "======================================================"
	@echo "Create a players directory before playing crossfire,  "
	@echo "otherwise crossfire cannot save your player character:"
	@echo "Type the following command as user: mkdir $HOME/players"
	@echo ""
	@echo "Read the docu, which is available in Postscript and HTML"
	@echo "format in the directory ${CFDIR}/doc"
	@echo "It is a good idea to install a WWW Browser like Mosaic"
	@echo "and to set some bookmarks that point to the different"
	@echo "files."

.include <bsd.port.mk>
