# New ports collection makefile for:	cpige
# Date created:				27 March, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cpige
DISTVERSION=	1.4
CATEGORIES=	audio
MASTER_SITES=	http://ed.zehome.com/cpige/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Icecast/Shoutcast stream ripper

USE_GMAKE=	yes

MAKE_ARGS=	CC="${CC}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/-1//}
PLIST_FILES=	bin/cpige

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
