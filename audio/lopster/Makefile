# New ports collection makefile for:	lopster
# Date created:		19 Oct 2000
# Whom:			Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	lopster
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://lopster.sourceforge.net/download/

MAINTAINER=	ports@oven.org
COMMENT=	GTK+ client for Napster

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-pthread=yes --with-zlib=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libogg.so.4)
WITH_LIBOGG=	yes
.endif

.if defined(WITH_LIBOGG)
LIB_DEPENDS+=	ogg.5:${PORTSDIR}/audio/libogg
.endif

pre-everything::
	@${ECHO_MSG} "You can specify WITH_LIBOGG to include Ogg support"

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

.include <bsd.port.post.mk>
