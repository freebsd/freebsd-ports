# New ports collection makefile for:	elvis
# Date created:		1999-09-01
# Whom:			Christian Weisgerber <naddy@unix-ag.uni-kl.de>
#
# $FreeBSD$
#

PORTNAME=	elvis
PORTVERSION=	2.1.4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/ \
		ftp://ftp.false.com/pub/elvis/ \
		ftp://ftp.fh-wedel.de/pub/elvis/
DISTNAME=	${PORTNAME}-2.1_4

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A clone of the ex/vi text editor

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --datadir=${PREFIX}/share/elvis
MAN1=		elvis.1 elvtags.1 ref.1

# Support building on systems with or without X11 installed.
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--with-x=no
.else
USE_XLIB=	yes

pre-fetch:
	@${ECHO_MSG} "To build this port without X11, define \"WITHOUT_X11\"."
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/configure

do-install:
.for file in elvis elvtags ref
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lib/${file}.man ${PREFIX}/man/man1/${file}.1
.endfor
	@${MKDIR} ${PREFIX}/share/elvis
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/share/elvis

.include <bsd.port.mk>
