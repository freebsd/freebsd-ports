# New ports collection makefile for:    xconq
# Date created:         2 Jun 1998
# Whom:                 Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	xconq
PORTVERSION=	7.4.1
PORTREVISION=	5
CATEGORIES=	games tcl tk
MASTER_SITES=	ftp://sources.redhat.com/pub/xconq/ \
		ftp://unix.hensa.ac.uk/mirrors/sources.redhat.com/pub/xconq/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical multi-player strategy game and game design system

GNU_CONFIGURE=	yes

USE_TK=		yes
USE_XORG=	xmu xaw
USE_GMAKE=	yes

MAN6=		xconq.6

SCOREDIR?=	/var/games/xconq
PLIST_SUB=	SCOREDIR=${SCOREDIR}

.include <bsd.port.pre.mk>

CFLAGS+=	-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}

CONFIGURE_ARGS=	--with-tclconfig=${TCL_LIBDIR} \
		--with-tkconfig=${TK_LIBDIR} \
		--enable-alternate-scoresdir=${SCOREDIR}

post-install:
.for file in xconq imf2x x2imf ximfapp
	${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/xconq/doc
	${INSTALL_DATA} ${WRKSRC}/doc-html/* ${PREFIX}/share/xconq/doc/
.endif

.include <bsd.port.post.mk>
