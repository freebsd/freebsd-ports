# New ports collection makefile for:	cpige
# Date created:				27 March, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cpige
DISTVERSION=	1.3-1
CATEGORIES=	audio
MASTER_SITES=	http://ed.zehome.com/cpige/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Icecast/Shoutcast stream ripper

MAKE_ARGS=	CC="${CC}" CLIBS="${LDFLAGS}" CFLAGS="${CFLAGS}"
WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTVERSION:S/-1//}
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
