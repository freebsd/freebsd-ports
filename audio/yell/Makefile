# New ports collection makefile for:   yell
# Date created:		10 August 2004
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	yell
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.critical.ch/yell/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A command line speaker bell using machine/speaker.h

PLIST_FILES=	bin/yell

ONLY_FOR_ARCHS=	i386

pre-everything::
.if !defined(WITH_SUID)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You can define WITH_SUID if you want yell to be installed with"
	@${ECHO_CMD} "the sticky bit (mode 4110)"
	@${ECHO_CMD} ""
.endif

do-build:
	${CC} ${WRKSRC}/yell.c ${CFLAGS} -o ${WRKSRC}/${PORTNAME}

do-install:
.if defined(WITH_SUID)
	${INSTALL_PROGRAM} -m 4110 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.else
	${INSTALL_PROGRAM} -m 0100 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
