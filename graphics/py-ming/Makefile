# New ports collection makefile for:	Python/Ming
# Date created:		16 Oct 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.2a
CATEGORIES=	graphics python
MASTER_SITES=	# none
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Python module for Ming which allows you to create Flash 4/5 movies

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/ming:patch
LIB_DEPENDS=	ming.3:${PORTSDIR}/graphics/ming

USE_PYTHON=	yes
USE_PERL5_BUILD=yes

MD5_FILE=	${.CURDIR}/../ming/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/py_ext
MAKE_ARGS=	PYTHON_VERSION="${PYTHON_VERSION}"

EXAMPLES=	../examples/python/*.py

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -s `cd ${PORTSDIR}/graphics/ming && ${MAKE} -V WRKDIR`/* ${WRKDIR}/

post-extract:
	${LN} -sf ../ming.i ${WRKSRC}/

post-patch:
	${PERL} -i -p \
		-e 's:\.\./common:../../ming/common:g;' \
		${WRKSRC}/../examples/python/*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/${PYTHON_VERSION}/ming
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/${PYTHON_VERSION}/ming/
.endfor
.endif

.include <bsd.port.mk>
