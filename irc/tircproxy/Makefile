# New ports collection makefile for: tircproxy
# Version required:	0.4.3
# Date created:		11 Aug 1999
# Whom:			Eugeny Kuzakov <CoreDumped@CoreDumped.null.ru>
#
# $FreeBSD$
#

DISTNAME=	tircproxy-0.4.3
CATEGORIES=	irc
MASTER_SITES=	http://www.mmedia.is/~bre/tircproxy/

MAINTAINER=	CoreDumped@CoreDumped.null.ru

WRKSRC=		${WRKDIR}/tircproxy-0.4
GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tircproxy ${PREFIX}/sbin

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing tircproxy docs in ${PREFIX}/share/doc/tircproxy"
	@${MKDIR} ${PREFIX}/share/doc/tircproxy && ${CHMOD} a+rx ${PREFIX}/share/doc/tircproxy
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tircproxy
.endif

.include <bsd.port.mk>
