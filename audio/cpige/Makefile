# New ports collection makefile for:	cpige
# Date created:				27 March, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cpige
DISTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://old.ed.zehome.com/cpige/ \
		http://T32.TecNik93.com/FreeBSD/ports/cpige/sources/

MAINTAINER=	itetcu@FreeBSD.org
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
