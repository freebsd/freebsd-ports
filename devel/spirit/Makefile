# ex:ts=8
# New ports collection makefile for:	spirit
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	spirit
PORTVERSION=	1.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An object oriented recursive descent parser generator framework

USE_REINPLCE=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-spirit-threadsafe

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} \
		${GREP} -lR "^htmldir" | ${XARGS} ${REINPLACE_CMD} \
		-e "s@libs/@share/doc/spirit/@"

.include <bsd.port.mk>
