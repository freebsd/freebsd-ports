# New ports collection makefile for:	grip
# Date created:				31 May 2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=	grip
PORTVERSION=	3.0.5
PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=grip

MAINTAINER=	alane@FreeBSD.org

LIB_DEPENDS=	id3-3.8.2:${PORTSDIR}/audio/id3lib \
		ghttp.1:${PORTSDIR}/www/libghttp

USE_X_PREFIX=	yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomelibs

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share

CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITH_DEBUG)
CFLAGS+=	-g
LDFLAGS+=	-g
.endif
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS}"
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ENV+= LIBS=${PTHREAD_LIBS}

post-install::
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
