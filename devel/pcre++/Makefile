# ex:ts=8
# Ports collection makefile for:	pcre++
# Date created:			Jan 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pcre++
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.daemon.de/scip/Apps/pcre++/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN3=	Pcre.3

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/html/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
