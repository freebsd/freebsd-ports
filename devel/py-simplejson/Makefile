# New ports collection makefile for:	py-simplejson
# Date created:				25 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	simplejson
PORTVERSION=	1.9.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP:source1 \
		http://peak.telecommunity.com/dist/:source2
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:source1 \
		ez_setup.py:source2
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	python@FreeBSD.org
COMMENT=	Simplejson is a simple, fast, extensible JSON encoder/decoder

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif

post-extract:
	${CP} ${DISTDIR}/ez_setup.py ${WRKSRC}

.include <bsd.port.mk>
