# ex:ts=8
# Ports collection makefile for:	parrot
# Date created:			Jul 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	parrot
PORTVERSION=	0.2.6
CATEGORIES=	devel
MASTER_SITES=	http://www.comuno.freeserve.co.uk/oss/parrot/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
NO_BUILD=	yes

FILE=	HtmlBackend.py PaxoBackend.py PytkBackend.py backend.py \
	generic.py inrep.py makbacl.py parrot.py pparser.py test.py \
	tokpos.py util.py
DOC=	INTRO README SPEC

do-install:
.for f in ${FILE}
	${INSTALL_DATA} ${WRKSRC}/$f ${PYTHON_SITELIBDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
