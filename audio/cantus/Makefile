# New ports collection makefile for:	cantus
# Date created:				22 May 2003
# Whom:					old@old.com.ua
#
# $FreeBSD$
#

PORTNAME=	cantus
PORTVERSION=	1.07
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	old@old.com.ua
COMMENT=	Tool for tagging and renaming MP3 and OGG/Vorbis files

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomelibs gnomehack gnomehier
WRKSRC=		${WRKDIR}/${DISTNAME:S/-1$//}

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
