# New ports collection makefile for:	zircon
# Date created:		19 Aug 1995
# Whom:			jkh / pst
#
# $FreeBSD$
#

PORTNAME=	zircon
PORTVERSION=	1.18.256
PORTREVISION=	2
CATEGORIES=	irc tk
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An X11 interface to Internet Relay Chat

LICENSE=	BSD

# zircon will start with tk84, but a lot of functions won't work
# a lot of variable names conflicts with new functions.
.if defined(ZIRCON_WITH_TCL84) || defined(ZIRCON_WITH_TK84)
USE_TK=		84
USE_TCL=	84
.else
USE_TK=		83
USE_TCL=	83
.endif

NO_BUILD=	yes

do-configure:
	${REINPLACE_CMD} -e 's=%%WISH%%=wish${TCL_VER}=' \
		-e 's=%%TCLSH%%=tclsh${TCL_VER}=' \
		${WRKSRC}/installZircon
	${REINPLACE_CMD} -e 's=%%WISH%%=wish${TCL_VER}=' \
		-e 's=%%TCL_INCLUDE%%=${LOCALBASE}/include/tcl${TCL_VER}=' \
		-e 's=/usr/local=${PREFIX}=' \
		${WRKSRC}/installer/unix.tcl

do-install:
	${ECHO_CMD} "set go {Yes}" >>${WRKSRC}/install.in
	(cd ${WRKSRC} && ./installZircon NoGui)

.include <bsd.port.mk>
