# New ports collection makefile for:	py-pyasn1
# Date created:				Sat Apr  8 21:37:32 CDT 2006
# Whom:					Martin Jackson <mhjacks@swbell.net>
#
# $FreeBSD$
#

PORTNAME=	asn1
PORTVERSION=	0.0.9a
CATEGORIES=	devel python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}-devel/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	mhjacks@swbell.net
COMMENT=	ASN.1 toolkit for Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyasn1

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

BASEDOCS=	CHANGES \
		README \
		LICENSE \
		TODO

DOCDOCS=	notes.html

EXAMPLE_FILES=	snmp.py \
		sshkey.py \
		x509.py

post-install:
# docs
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${BASEDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
. for f in ${DOCDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
. endfor
.endif
# examples
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
