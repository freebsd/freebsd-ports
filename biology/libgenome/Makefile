# ex:ts=8
# Ports collection makefile for:	libgenome
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libgenome
PORTVERSION=	0.5.0
CATEGORIES=	biology
MASTER_SITES=	http://www.libgenome.org/releases/
DISTNAME=	libGenome-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
