# New ports collection makefile for:	cantus
# Date created:				22 May 2003
# Whom:					old@old.com.ua
#
# $FreeBSD$
#

PORTNAME=	cantus
PORTVERSION=	1.07
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://sam.homeunix.com/software.manicsadness.com-step4/releases/cantus/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	old@old.com.ua
COMMENT=	Tool for tagging and renaming MP3 and OGG/Vorbis files

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomelibs gnomehack
WRKSRC=		${WRKDIR}/${DISTNAME:S/-1$//}

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
