# New ports collection makefile for:    pychecker
# Date created:         		13 April 2001
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pychecker
PORTVERSION=	0.8.11
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=		CHANGELOG COPYRIGHT KNOWN_BUGS MAINTAINERS README TODO \
		VERSION

post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor

.include <bsd.port.mk>
