# ex:ts=8
# Ports collection makefile for:	wizard
# Date created:			Jan 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wizard
PORTVERSION=	1.4
CATEGORIES=	devel python
# mastersite disappeared in May 2002
MASTER_SITES=	# http://www.zolera.com/opensrc/wizard/

DEPRECATED=	"master site disappeared, author stopped work 2002"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classes for writing MS-style 'wizards'

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${CP} -R ${WRKSRC}/doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
