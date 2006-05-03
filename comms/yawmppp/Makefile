# New ports collection makefile for:	yawmppp
# Date created:				07 Mar 2000
# Whom:					Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	yawmppp
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	comms windowmaker
MASTER_SITES=	ftp://ftp.seul.org/pub/yawmppp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Window Maker dockapp that helps with easy use of pppd

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_XPM=	yes
CONFIGURE_ENV=	GTKCONFIG="${GTK_CONFIG}" CFLAGS="${CFLAGS} -I${X11BASE}/include"
CONFIGURE_ARGS=	--x-includes="${X11BASE}/include" \
		--x-libraries="${X11BASE}/lib"

MAN1=		yawmppp.1x

pre-patch:
	@${REINPLACE_CMD} -e "s@-g -O2@${CFLAGS}@g; s@-O2 -Wall@${CFLAGS} -Wall@g; \
			s@-O2@${CFLAGS}@g" ${WRKSRC}/*/Makefile.in \
			${WRKSRC}/configure ${WRKSRC}/*/*/Makefile.in
	@${REINPLACE_CMD} -e 's!\/usr\/local!${PREFIX}!; \
		s!/usr/bin!${PREFIX}/bin!' ${WRKSRC}/src/ycommon.c
	@${REINPLACE_CMD} -e 's|/etc/ppp\(/yagetmodemspeed\)|${PREFIX}/bin\1|' \
		${WRKSRC}/src/gtksetup/applet.c
	@${REINPLACE_CMD} -e 's|tac|cat|' ${WRKSRC}/src/dockapp/getmodemspeed.c

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
