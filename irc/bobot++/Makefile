# ex:ts=8
# New ports collection makefile for:	bobot++
# Date created:			Sep 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bobotpp
PORTVERSION=	2.0.2
PORTREVISION=	4
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	bobotpp

MAINTAINER=	michael@ranner.eu
COMMENT=	An IRC bot written in C++

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.if defined(WITHOUT_GUILE)
CONFIGURE_ARGS+=	--disable-scripting
.else
LIB_DEPENDS+=	guile.20:${PORTSDIR}/lang/guile
CONFIGURE_ARGS+=	--enable-scripting
.endif

.if defined(WITH_TELNET)
CONFIGURE_ARGS+=	--enable-telnetserver
.else
CONFIGURE_ARGS+=	--disable-telnetserver
.endif

post-extract:
	@${FIND} ${WRKSRC}/scripts -name "*~" -delete

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/doc/* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
	@${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/scripts ${DATADIR}
.endif

.include <bsd.port.mk>
