# New ports collection makefile for:	tvp
# Date Created:		3 Jul 1996
# Whom:			Tim Vanderhoek <ac199@hwcn.org>
#
# $FreeBSD$
#

PORTNAME=	tvp
PORTVERSION=	0.9.7.1
PORTREVISION=	1
CATEGORIES=	games tk82
MASTER_SITES=	http://www3.sympatico.ca/john.vanderhoek/tim/src/president/

MAINTAINER=	hoek@FreeBSD.org
COMMENT=	Play the cardgame President (or Ass) against 3 AIs

# Comment-out this (and CFLAGS) to compile only the CLI and ansi interfaces
LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-carddir=${PREFIX}/share/games/tvp
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/tcl8.2 \
			  -I${LOCALBASE}/include/tk8.2" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib \
		      -ltcl82 -ltk82 -lX11 -lm"
#CFLAGS+=		-lX11 -lm -ltcl82 -ltk82 \
#			-L${LOCALBASE}/lib -L${X11BASE}/lib
USE_PERL5_BUILD=yes

MAN6=	tvp.6
MLINKS=	tvp.6 xprez.6 - aprez.6 - prez.6

DOCFILES=	aprez.txt libass.txt president.txt prez.txt xprez.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tvp
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${PREFIX}/share/doc/tvp
.endfor
.endif
	${INSTALL_MAN} ${FILESDIR}/tvp.6 ${PREFIX}/man/man6/tvp.6
	a='${PREFIX}/share/doc/tvp/' ${PERL} -pi -e 's/TOKEN/$$ENV{a}/' \
		${PREFIX}/man/man6/tvp.6
	${STRIP_CMD} ${PREFIX}/bin/aprez ${PREFIX}/bin/prez ${PREFIX}/bin/xpwish

.include <bsd.port.mk>
