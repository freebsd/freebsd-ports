# New ports collection makefile for:    xcoral
# Date created:         1995/10/02
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	xcoral
PORTVERSION=	3.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes

GNU_CONFIGURE=	yes

LIBFILES=	DEPEND README cmd.sc color.sc comments.sc compare-win.sc \
		complete-word.sc describe.sc edir.sc edt.sc example.sc \
		french.sc hack-filename.sc hanoi.sc head.sc html.sc \
		java.sc keydef-ext.sc latex-macros.sc latex.sc \
		man.dtex misc-commands.sc mode-ext.sc mode.sc mouse.sc \
		rcs.sc save.sc sun-keydef.sc title.sc top-ten.sc \
		utilities.sc version.sc window-utilities.sc xcoralrc.lf

do-install:
	@${MKDIR} ${PREFIX}/lib/xcoral/

.for i in ${LIBFILES}
	${INSTALL_DATA} ${WRKSRC}/SmacLib/${i} ${PREFIX}/lib/xcoral/
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/xcoral ${PREFIX}/bin/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xcoral/HTML/icons
	${CP} -r ${WRKSRC}/Doc/ ${PREFIX}/share/doc/xcoral/
.endif

.include <bsd.port.mk>
