# New ports collection makefile for:	yawmppp
# Date created:				07 Mar 2000
# Whom:					Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	yawmppp
PORTVERSION=	2.0.2
CATEGORIES=	comms windowmaker
MASTER_SITES=	ftp://ftp.seul.org/pub/yawmppp/ \
		http://www.dcc.unicamp.br/~guazzibe/yawmppp/arch/

MAINTAINER=	pat@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_XPM=	yes
CONFIGURE_ENV=	GTKCONFIG="${GTK_CONFIG}" CFLAGS="${CFLAGS} -I${X11BASE}/include"
CONFIGURE_ARGS=	--x-includes="${X11BASE}/include" \
		--x-libraries="${X11BASE}/lib"

MAN1=		yawmppp.1x

pre-patch:
	@${PERL} -pi -e "s@-g -O2@${CFLAGS}@g; s@-O2 -Wall@${CFLAGS} -Wall@g; \
			s@-O2@${CFLAGS}@g" ${WRKSRC}/*/Makefile.in \
			${WRKSRC}/configure ${WRKSRC}/*/*/Makefile.in
	@${PERL} -pi -e 's!\/usr\/local!${PREFIX}!; \
		s!/usr/bin!${PREFIX}/bin!' ${WRKSRC}/src/ycommon.c
	@${PERL} -pi.orig -e 's|/etc/ppp/yagetmodemspeed|${PREFIX}/bin/yagetmodemspeed|' \
		${WRKSRC}/src/gtksetup/applet.c
	@${PERL} -pi.orig -e 's|tac|cat|' ${WRKSRC}/src/dockapp/getmodemspeed.c

do-install:
.for file in dockapp/yagetmodemspeed dockapp/${PORTNAME} gtklog/${PORTNAME}.log \
	gtksetup/${PORTNAME}.pref thinppp/${PORTNAME}.thin
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${file} ${PREFIX}/bin
.endfor
	@${INSTALL_MAN} ${WRKSRC}/src/${PORTNAME}.1x ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGELOG FAQ README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
