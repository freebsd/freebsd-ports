# New ports collection makefile for:	rosegarden
# Version required:	2.1pl2
# Date created:		04 Aug 1996
# Whom:			shanee@augusta.de
#
# $FreeBSD$
#

DISTNAME=	rosegarden-2.1pl2
CATEGORIES=	audio
MASTER_SITES=	http://www.all-day-breakfast.com/rosegarden/patches/

MAINTAINER=	shanee@augusta.de

BUILD_DEPENDS=	${LOCALBASE}/lib/tclmidi/tclmidi31.so:$(PORTSDIR)/audio/tclmidi
RUN_DEPENDS=	${LOCALBASE}/lib/tclmidi/tclmidi31.so:$(PORTSDIR)/audio/tclmidi

GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS=	--with-tclincl=${LOCALBASE}/include/tcl8.2/
CONFIGURE_ENV=	LIBS="-L${PREFIX}/lib"

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/app-defaults
	@( \
	 cd ${WRKSRC} ; ${SETENV} PREFIX="${PREFIX}" ./do-install \
	)

post-install:
	${MV} -i ${PREFIX}/bin/rosegarden ${PREFIX}/bin/rosegarden-bin
	${SED} s-%%PREFIX%%-${PREFIX}-g ${FILESDIR}/rosegarden >${WRKDIR}/rosegarden
	${INSTALL_SCRIPT} ${WRKDIR}/rosegarden ${PREFIX}/bin

.include <bsd.port.mk>
