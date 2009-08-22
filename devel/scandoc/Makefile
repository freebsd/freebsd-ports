# New ports collection makefile for:   scandoc
# Date created:        13 April 2001
# Whom:                Christopher Elkins <chrise@scardini.com>
#
# $FreeBSD$
#

PORTNAME=	scandoc
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C/C++ documentation generator

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for i in COPYING ChangeLog README scandoc.html
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/${PORTNAME}
.endfor
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}/images
	${CP} -R ${WRKSRC}/images/ ${PREFIX}/share/doc/${PORTNAME}/images/
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}/templates
	${CP} -R ${WRKSRC}/templates/ ${PREFIX}/share/doc/${PORTNAME}/templates/
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}/test
	${CP} -R ${WRKSRC}/test/ ${PREFIX}/share/doc/${PORTNAME}/test/
.endif

.include <bsd.port.mk>
