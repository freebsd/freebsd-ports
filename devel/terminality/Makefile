# ex:ts=8
# New ports collection makefile for:	terminality
# Date created:			Apr 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	terminality
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES= 	http://members.optushome.com.au/darkmoon7/
DISTNAME=	tn-${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org

WRKSRC=		${WRKDIR}/tn
USE_GMAKE=	yes
MAKE_ENV=	CPP=${CXX} INSTALL="${INSTALL}" INSTALL_DATA="${INSTALL_DATA}"

post-patch:
	@find ${WRKSRC} -name Makefile | xargs \
		${PERL} -pi -e "s, -lstdc\\+\\+,,g"
	@${PERL} -pi -e "s,make,gmake,g ; \
		s,/usr/local,${PREFIX},g" ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/terminality
	${CP} -R ${WRKSRC}/doc/ ${PREFIX}/share/doc/terminality
.endif

.include <bsd.port.mk>
