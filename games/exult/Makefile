# New ports collection makefile for:	exult
# Date created:		18 February 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	exult
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tiamat@comset.net
COMMENT=	Ultima VII engine

RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_XLIB=	yes
USE_SDL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${X11BASE}/include \
		LDFLAGS="-L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-x \
		--disable-tools \
		--disable-sdltest

MAN6=		exult.6

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^DEBUG_FLAGS|#DEBUG_FLAGS|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exult ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/exult.6 ${MANPREFIX}/man/man6
	@${MKDIR} ${DATADIR}
.for file in exult.flx exult_bg.flx exult_si.flx midisfx.flx
	${INSTALL_DATA} ${WRKSRC}/data/${file} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${SED} 's:/usr/local:${PREFIX}:g' ${PKGMESSAGE}

.include <bsd.port.mk>
