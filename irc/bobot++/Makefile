# ex:ts=8
# New ports collection makefile for:	bobot++
# Date created:			Sep 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bobot++
PORTVERSION=	1.97
CATEGORIES=	irc
MASTER_SITES=	http://pltplp.net/bobot++/archive/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

.if defined(WITH_GUILE)
LIB_DEPENDS+=	guile:${PORTSDIR}/lang/guile
GUILE_CONFIG=	${LOCALBASE}/bin/guile-config
CONFIGURE_ARGS+=	--enable-script
.endif

.if defined(WITH_TELNET)
CONFIGURE_ARGS+=	--enable-telnetserver
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%GUILE_CONFIG%%,${GUILE_CONFIG},g ; \
		s,%%PTHREAD_CFLAGS%%,${PTHREAD_CFLAGS},g ; \
		s,%%PTHREAD_LIBS%%,${PTHREAD_LIBS},g" ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bobot++ ${PREFIX}/bin

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/doc/* ${DOCSDIR}
	@${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/examples ${DATADIR}
	${CP} -R ${WRKSRC}/scripts ${DATADIR}
.endif

.include <bsd.port.mk>
