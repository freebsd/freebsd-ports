# New ports collection makefile for:	rosegarden
# Version required:	2.1
# Date created:		04 Aug 1996
# Whom:			shanee@augusta.de
#
# $FreeBSD$
#

DISTNAME=	rosegarden-2.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.maths.bath.ac.uk/pub/dream/ROSE/ \
		ftp://ftp.unina.it/pub/Unix/pkgs/audio/rosegarden/ \
		ftp://sunsite.auc.dk//disk6/linuxberg.com/files/x11/media/ \
		ftp://ftp.flashnet.it//mirror/8/linuxberg/files/x11/media/
EXTRACT_SUFX=	-sources.tar.gz

MAINTAINER=	shanee@augusta.de

BUILD_DEPENDS=	${LOCALBASE}/lib/tclmidi/tclmidi31.so:$(PORTSDIR)/audio/tclmidi
RUN_DEPENDS=	${LOCALBASE}/lib/tclmidi/tclmidi31.so:$(PORTSDIR)/audio/tclmidi

GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
USE_XLIB=	yes
CONFIGURE_ARGS=	--with-tclincl=${LOCALBASE}/include/tcl8.0/
CONFIGURE_ENV=	LIBS="-L${PREFIX}/lib"

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/app-defaults
	@( \
	 cd ${WRKSRC} ; ${SETENV} PREFIX="${PREFIX}" ./do-install \
	)

.include <bsd.port.mk>
