# New ports collection makefile for:    py-gdbm
# Date created:         03 October 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdbm
PORTVERSION= 	${PYTHON_PORTVERSION}
CATEGORIES=	databases python
MASTER_SITES=	ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	tg@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

DIST_SUBDIR=	python
USE_PYTHON=	yes
WRKSRC=		${PYTHON_WRKSRC}/Modules
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
ALL_TARGET=	sharedmods
MAKE_FLAGS=	OPT="${CFLAGS}"

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}
	@${CP} ${PYTHON_LIBDIR}/config/Makefile.pre.in ${WRKSRC}

do-configure:
	@(cd ${WRKSRC}; \
		${SETENV} ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

do-install:
	${INSTALL_DATA} ${WRKSRC}/gdbmmodule.so ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
