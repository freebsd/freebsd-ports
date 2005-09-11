# New ports collection makefile for:	tinystats
# Date created:				07 July 2005
# Whom:				Filippo Natali <filippo.natali@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tinystats
PORTVERSION=	1.1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.morettoni.net/bsd/

MAINTAINER=	filippo.natali@gmail.com
COMMENT=	DJB's tinydns statistics generator

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=

OPTIONS=	IPV6 "Enable IPv6 support" off

PLIST_FILES=	bin/tinystats \
		%%EXAMPLESDIR%%/tinydns.log.run.sample \
		%%EXAMPLESDIR%%/tinydns.sh.sample \
		%%EXAMPLESDIR%%/update_slave.sh.sample \
		%%EXAMPLESDIR%%/start_slave.sh.sample \
		%%EXAMPLESDIR%%/Makefile.sample
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	README LICENSE THANKS

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
MAKE_ARGS+=	-DWITH_IPV6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tinystats ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tinydns.sh.sample ${WRKSRC}/tinydns.log.run.sample \
			${WRKSRC}/update_slave.sh.sample ${WRKSRC}/start_slave.sh.sample ${WRKSRC}/Makefile.sample ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/LICENSE ${WRKSRC}/THANKS ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
