# New ports collection makefile for:	crossfire
# Date created:         So  27 Okt 1996 12:25:55 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	crossfire
PORTVERSION=	0.94.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/crossfire/old/ \
		ftp://ftp.sunet.se/pub/unix/games/crossfire/old/
DISTFILES=	${CF_SOURCES} ${CF_DOC} ${CF_MAPS} ${CF_SOUNDS} \
		${CF_ARCH} ${CF_CLSERV}
EXTRACT_ONLY=	${CF_SOURCES} ${CF_DOC}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	rplay.1:${PORTSDIR}/audio/rplay
BUILD_DEPENDS=	xmkmf:${PORTSDIR}/devel/imake-4

USE_PERL5=	yes
USE_XPM=	yes
MAN6=		crossedit.6 crossfire.6

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

# Do you want to be able to rebuild documentation after installing the game
# to produce Postscript documentation with colored icons ?! You have to go
# into the workdir and to build everything manually.
# You need TeX to do this ! Please read the README's !
WANT_CF_ARCH=	NO

CF_SOURCES=	${PORTNAME}-${PORTVERSION}.tar.gz
CF_MAPS=	${PORTNAME}-${PORTVERSION}.maps.tar.gz
# crossfire doc ready for use
CF_DOC=		${PORTNAME}-${PORTVERSION}.doc.tar.gz
# no newer sounds available
CF_SOUNDS=	${PORTNAME}-0.92.7.sounds.tar.gz
.if ${WANT_CF_ARCH} == YES || ${WANT_CF_ARCH} == yes
# only for rebuild of doc
CF_ARCH=	${PORTNAME}-${PORTVERSION}.arch.tar.gz
.endif
#CF_CLSERV=	eutl.tar.gz		# only for client/server
CFDIR=		${PREFIX}/lib/crossfire	# crossfire base directory

post-patch:
	@${PERL} -pi -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%X11BASE%%|${X11BASE}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/config/crosssite.def

do-configure:
	@(cd ${CONFIGURE_WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF})

# If you want to re-make playbook and spoiler you need the ARCH
# files and a TeX version with a ,great' amount of max_mem
# (I had to rebuild teTeX, that already is in fact ,BigTeX')
.if ${WANT_CF_ARCH} == YES || ${WANT_CF_ARCH} == yes
post-configure:
	${TAR} -C ${CFDIR} -xzf ${_DISTDIR}/${CF_ARCH}
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/crossedit.man \
		 ${MANPREFIX}/man/man6/crossedit.6
	${INSTALL_MAN} ${WRKSRC}/doc/crossfire.man \
		${MANPREFIX}/man/man6/crossfire.6
	@${TAR} -C ${CFDIR}/lib -xzf ${_DISTDIR}/${CF_MAPS}
	@${TAR} -C ${CFDIR} -xzf ${_DISTDIR}/${CF_SOUNDS}
	@${TOUCH} ${CFDIR}/lib/bookarch
	@${CHMOD} 664 ${CFDIR}/lib/bookarch
	@${TOUCH} ${CFDIR}/lib/forbid
	@${CHMOD} 664 ${CFDIR}/lib/forbid
	@${TOUCH} ${CFDIR}/lib/players/.keep_me
	@${TOUCH} ${CFDIR}/lib/unique-items/.keep_me
	@${CHOWN} -R root.games ${CFDIR}
	@${CHMOD} 0664 ${CFDIR}/lib/highscore
	@${CHOWN} root.games ${PREFIX}/bin/crossfire
	@${CHMOD} 2555 ${PREFIX}/bin/crossfire
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/crossfire
	@${TAR} -C ${WRKDIR}/${PORTNAME}-${PORTVERSION}-doc -cf - . | \
		${TAR} -C ${PREFIX}/share/doc/crossfire --unlink -xf -
.endif
	@${SED} -e "s:/usr/local:${LOCALBASE}:g" ${PKGMESSAGE}

.include <bsd.port.post.mk>
