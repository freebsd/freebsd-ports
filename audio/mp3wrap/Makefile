# New ports collection makefile for:	audio/mp3wrap
# Date created:				30.05.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	mp3wrap
PORTVERSION=	0.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	q@uni.de
COMMENT=	Utility to merge mp3 files (and other formats)

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		mp3wrap.1
PLIST_FILES=	bin/mp3wrap

.include <bsd.port.mk>
