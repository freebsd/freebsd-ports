# New ports collection makefile for:	zircon
# Date created:		19 Aug 1995
# Whom:			jkh / pst
#
# $FreeBSD$
#

PORTNAME=	zircon
PORTVERSION=	1.18.256
PORTREVISION=	1
CATEGORIES=	irc tk84
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An X11 interface to Internet Relay Chat

# zircon will start with tk84, but a lot of functions won't work
# a lot of variable names conflicts with new functions.
.if defined(ZIRCON_WITH_TCL84) || defined(ZIRCON_WITH_TK84)
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
.else
RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
.endif

NO_BUILD=	yes
USE_REINPLACE=	yes
.if defined(ZIRCON_WITH_TCL84) || defined(ZIRCON_WITH_TK84)
TCL_VER=	8.4
.else
TCL_VER=	8.3
.endif

do-configure:
	${REINPLACE_CMD} -e 's=%%WISH%%=wish${TCL_VER}=' \
		-e 's=%%TCLSH%%=tclsh${TCL_VER}=' \
		${WRKSRC}/installZircon
	${REINPLACE_CMD} -e 's=%%WISH%%=wish${TCL_VER}=' \
		-e 's=%%TCL_INCLUDE%%=${LOCALBASE}/include/tcl${TCL_VER}=' \
		${WRKSRC}/installer/unix.tcl

do-install:
	${ECHO_CMD} "set go {Yes}" >>${WRKSRC}/install.in
	(cd ${WRKSRC} && ./installZircon NoGui)

.include <bsd.port.mk>
