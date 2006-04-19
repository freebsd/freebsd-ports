# New ports collection makefile for:	cpige
# Date created:				27 March, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cpige
DISTVERSION=	1.4-2
CATEGORIES=	audio
MASTER_SITES=	http://ed.zehome.com/cpige/ \
		http://sce-tindy.tecnik93.com/FreeBSD/ports/cpige/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Icecast/Shoutcast stream ripper

USE_GMAKE=	yes

MAKE_ARGS=	CC="${CC}"

PLIST_FILES=	bin/cpige

.ifdef(WITH_DEBUG)
CFLAGS+=	-g -DDEBUG
STRIP=
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
