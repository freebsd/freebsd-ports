# New ports collection makefile for:	py-unidecode
# Date created:				22 October 2009
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	unidecode
PORTVERSION=	0.04.4
CATEGORIES=	converters python
MASTER_SITES=	http://code.zemanta.com/tsolc/unidecode/releases/ \
		http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Unidecode-${PORTVERSION}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	ASCII transliterations of Unicode text

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Unidecode

.include <bsd.port.mk>
