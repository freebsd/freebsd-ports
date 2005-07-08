# New ports collection makefile for:    xconq
# Date created:         2 Jun 1998
# Whom:                 Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	xconq
PORTVERSION=	7.4.1
PORTREVISION=	3
CATEGORIES=	games tcl84 tk84
MASTER_SITES=	ftp://sources.redhat.com/pub/xconq/ \
		ftp://unix.hensa.ac.uk/mirrors/sources.redhat.com/pub/xconq/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical multi-player strategy game and game design system

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclconfig=${PREFIX}/lib/tcl8.4 \
		--with-tkconfig=${PREFIX}/lib/tk8.4 \
		--enable-alternate-scoresdir=${SCOREDIR}

USE_XLIB=	yes
USE_GMAKE=	yes

CFLAGS+=	-I ${PREFIX}/include/tcl8.4 \
		-I ${PREFIX}/include/tk8.4

MAN6=		xconq.6

SCOREDIR?=	/var/games/xconq
PLIST_SUB=	SCOREDIR=${SCOREDIR}

post-install:
.for file in xconq imf2x x2imf ximfapp
	${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/xconq/doc
	${INSTALL_DATA} ${WRKSRC}/doc-html/* ${PREFIX}/share/xconq/doc/
.endif

.include <bsd.port.mk>
