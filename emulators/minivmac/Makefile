# New ports collection makefile for:	minivmac
# Date created:				9 November 2002
# Whom:					Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	minivmac
PORTVERSION=	0.1.7
CATEGORIES=	emulators
MASTER_SITES=	http://www.gryphel.com/c/download/ \
		${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/minivmac/}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=	.tgz

MAINTAINER=	blackend@FreeBSD.org
COMMENT=	A miniature Macintosh emulator

USE_REINPLACE=	yes
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
# CC,CFLAGS,LD safeness
# X11 base safeness
		@${REINPLACE_CMD} -E -e 's,cc,${CC} ${CFLAGS} -I${X11BASE}/include,; \
			s,^(LinkLine).*$$,\1="${CC}",; \
			s,/usr/X11R6,${X11BASE},' \
			${WRKSRC}/tool/bash/build

do-build:
		@cd ${WRKSRC}/tool/bash && ${SH} build

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/drv/minivmac ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		@${MKDIR} ${PREFIX}/share/doc/minivmac
		@${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/minivmac
.endif

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
