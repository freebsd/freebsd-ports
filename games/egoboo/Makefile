# New ports collection makefile for:	egoboo
# Date created:				Apr 28 2003
# Whom:					Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$

PORTNAME=	egoboo
PORTVERSION=	2.22
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	ego222

MAINTAINER=	Jan.Stocker@t-online.de
COMMENT=	A 3d dungeon crawling adventure in the spirit of NetHack

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_SDL=	yes
USE_MESA=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

pre-patch:
	@${FIND} ${WRKSRC}/.. -type d -name CVS | ${XARGS} ${RM} -rf

post-patch:
	@cd ${WRKSRC}/code && ${GMAKE} clean
	@${REINPLACE_CMD} -e 's|sdl-config|\${SDL_CONFIG}|g ; \
		s|/usr/X11/|${X11BASE}/|g ; s|CC=|#CC=|g; \
		s|-O3|${CFLAGS}|g; s|-ffast-math||g' ${WRKSRC}/code/Makefile

do-build:
	@cd ${WRKSRC}/code && ${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	@${MKDIR} "${PREFIX}/share/${PORTNAME}"
	@${MKDIR} "${PREFIX}/share/${PORTNAME}/import"
	@${CHGRP} games ${PREFIX}/share/${PORTNAME}/import"
	@${CHMOD} g+ws ${PREFIX}/share/${PORTNAME}/import
	@${TAR} -cf - -C "${WRKSRC}" modules | \
	${TAR} xf - -C "${PREFIX}/share/${PORTNAME}"
	@${TAR} -cf - -C "${WRKSRC}" players |\
	${TAR} xf - -C "${PREFIX}/share/${PORTNAME}"
	@${TAR} -cf - -C "${WRKSRC}" text |\
	${TAR} xf - -C "${PREFIX}/share/${PORTNAME}"
	@${TAR} -cf - -C "${WRKSRC}" basicdat |\
	${TAR} xf - -C "${PREFIX}/share/${PORTNAME}"
	@${INSTALL_PROGRAM} ${WRKSRC}/code/egoboo ${PREFIX}/share/${PORTNAME}/egoboo-real
	@${CHGRP} games ${PREFIX}/share/${PORTNAME}/egoboo-real
	@${CHMOD} g+s ${PREFIX}/share/${PORTNAME}/egoboo-real
	@(${ECHO_CMD} "#!/bin/sh"; ${ECHO_CMD} "cd ${PREFIX}/share/${PORTNAME}"; \
	  ${ECHO_CMD} "./egoboo-real $$*") > ${PREFIX}/bin/egoboo
	@${CHMOD} a+x ${PREFIX}/bin/egoboo
	@${INSTALL_DATA} -m 644 ${WRKSRC}/*.txt  ${PREFIX}/share/${PORTNAME}
	@${CHGRP} games ${PREFIX}/share/${PORTNAME}/basicdat/*.txt
	@${CHMOD} g+w   ${PREFIX}/share/${PORTNAME}/basicdat/*.txt

.include <bsd.port.mk>
