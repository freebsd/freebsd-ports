# New ports collection makefile for:	tuxpaint
# Date created:				14 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint
PORTVERSION=	0.9.14
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Drawing program designed for young children

USE_GMAKE=	yes
USE_SDL=	image mixer sdl ttf
USE_GNOME=	intltool
USE_REINPLACE=	yes

MAN1=		tuxpaint.1 tuxpaint-import.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		needs wide character string functions in libc
.endif

post-extract:
# Remove CVS directories
	@${FIND} ${WRKSRC} -type d -name CVS -print0 | \
		${XARGS} -0 ${RM} -rf

post-patch:
# Fix Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}| ; \
			s|$$(PREFIX)/share/tuxpaint|${DATADIR}| ; \
			s|$$(PREFIX)/share/doc/tuxpaint|${DOCSDIR}|; \
			s|sdl-config|${SDL_CONFIG}|'  \
				${WRKSRC}/${MAKEFILE}

# Documentation (optional)
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|install-doc\([^:]\)|\1|' ${WRKSRC}/${MAKEFILE}
.endif

# Fix SDL include statement and remove "#error" statement
	@${REINPLACE_CMD} -e 's|\(#include.*\)SDL/\(SDL.*\)|\1\2| ; \
			s|#error.*||' \
				${WRKSRC}/src/${PORTNAME}.c

.include <bsd.port.post.mk>
