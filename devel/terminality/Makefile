# ex:ts=8
# New ports collection makefile for:	terminality
# Date created:			Apr 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	terminality
PORTVERSION=	2.0
CATEGORIES=	devel
MASTER_SITES= 	http://members.optushome.com.au/darkmoon7/code/tn/
DISTNAME=	tn-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
MAKE_ENV=	CPP=${CXX} INSTALL="${INSTALL}" INSTALL_DATA="${INSTALL_DATA}"

post-patch:
	@find ${WRKSRC} -name Makefile | xargs \
		${PERL} -pi -e "s, -lstdc\\+\\+,,g"
	@${PERL} -pi -e "s,make,gmake,g ; \
		s,/usr/local,${PREFIX},g" ${WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
