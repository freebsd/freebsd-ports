# New ports collection makefile for:    imaze
# Version required:	1.3
# Date created:         27. April 1996
# Whom:                 Ronald Kuehn <kuehn@rz.tu-clausthal.de>
#
# $Id: Makefile,v 1.12 1998/09/28 02:07:19 steve Exp $
#

DISTNAME=       imaze
PKGNAME=	imaze-1.3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tu-clausthal.de/pub/unix/games/imaze/ \
		ftp://ftp.tu-clausthal.de/pub/unix/games/imaze/sounds/
DISTFILES=	imaze1.3.tar.Z imaze.tar

MAINTAINER=	kuehn@rz.tu-clausthal.de

#
# Sound support currently only exists for the XView version (apperently
# broken for the pcm driver; worked for voxware). The not yet released
# version 1.4 will add sound support for the Motif version too.
# XView is the default. If you want the Motif version, define FORCE_MOTIF=yes.
#
.if !(defined(HAVE_MOTIF) && defined(FORCE_MOTIF) && ${FORCE_MOTIF} == "yes") \
	|| defined(PACKAGE_BUILDING)
LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview-lib
.endif

EXTRACT_ONLY=	imaze1.3.tar.Z
USE_X_PREFIX=	yes
MAN6=		genlab.6 imaze.6 imazesrv.6 ninja.6
MANCOMPRESSED=	maybe

SOUNDDIR=${PREFIX}/share/imaze/sounds

.if !defined(NOMANCOMPRESS)
compresscommand=gzip -9nf
.else
compresscommand=":"
.endif

post-extract:
	@tar xf ${DISTDIR}/imaze.tar -C ${WRKDIR}/imaze

do-build:
	@(cd ${WRKSRC}/source; ${MAKE} SOUNDDIR=${SOUNDDIR} \
		FORCE_MOTIF=${FORCE_MOTIF} MOTIFLIB="${MOTIFLIB}" \
		X11BASE=${X11BASE} freebsd)

do-install:
	@(cd ${WRKSRC}/source && for f in imaze imazesrv ninja genlab;\
		do ${INSTALL_PROGRAM} $$f ${PREFIX}/bin; done)
	@(cd ${WRKSRC}/man6 && for f in *.6;\
		do ${INSTALL_MAN} $$f ${PREFIX}/man/man6;\
		${compresscommand} ${PREFIX}/man/man6/$$f; done)
	@mkdir -p ${PREFIX}/share/imaze/labs
	@(cd ${WRKSRC}/labs && for f in *.lab;\
		do ${INSTALL_DATA} $$f ${PREFIX}/share/imaze/labs; done)
	@mkdir -p ${SOUNDDIR}
	@(cd ${WRKSRC}/sounds && for f in *.au;\
		do ${INSTALL_DATA} $$f ${SOUNDDIR}; done)
	@(cd ${WRKSRC} && for f in Xdefaults.Motif Xdefaults.OpenWindows;\
		do ${INSTALL_DATA} $$f ${PREFIX}/share/imaze/$$f.example;\
		done; \
		${INSTALL_DATA} README ${PREFIX}/share/imaze)
	@echo "Please read the file \"README\" in \"${PREFIX}/share/imaze\"."

.include <bsd.port.mk>
