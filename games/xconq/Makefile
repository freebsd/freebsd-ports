# New ports collection makefile for:    xconq
# Date created:         2 Jun 1998
# Whom:                 Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	xconq
PORTVERSION=	7.3.3
CATEGORIES=	games
MASTER_SITES=	ftp://sourceware.cygnus.com/pub/xconq/ \
		ftp://ftp.freesoftware.com/pub/sourceware/xconq/ \
		ftp://unix.hensa.ac.uk/mirrors/sourceware.cygnus.com/pub/xconq/

MAINTAINER=	croyle@gelemna.org

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclconfig=${PREFIX}/lib/tcl8.0 \
		--with-tkconfig=${PREFIX}/lib/tk8.0 \
		--enable-alternate-scoresdir=${SCOREDIR}

USE_XLIB=	yes
USE_GMAKE=	yes

CFLAGS+=	-I ${PREFIX}/include/tcl8.0 \
		-I ${PREFIX}/include/tk8.0

MAN6=		xconq.6

SCOREDIR?=	/var/games/xconq
PLIST_SUB=	SCOREDIR=${SCOREDIR}

post-install:
.for file in xconq imf2x x2imf ximfapp
	strip ${PREFIX}/bin/${file}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/xconq/doc
	${INSTALL_DATA} ${WRKSRC}/doc-html/* ${PREFIX}/share/xconq/doc/
.endif

.include <bsd.port.mk>
