# New ports collection makefile for:    py-gdbm
# Date created:         03 October 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdbm
PORTVERSION=	${PYTHON_PORTVERSION}
CATEGORIES=	databases python
MASTER_SITES=	http://www.python.org/ftp/python/${PORTVERSION}/ \
		http://SunSITE.Informatik.RWTH-Aachen.DE/python/ftp/python/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	tg@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
WRKSRC=		${PYTHON_WRKSRC}/Modules

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include <bsd.port.mk>
