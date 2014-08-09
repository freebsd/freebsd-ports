# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdbm
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	PYTHON
MASTER_SITE_SUBDIR=	ftp/python/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings to the GNU dbm library

LICENSE=	PSFL

LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm

PORTSCOUT=	ignore:1

USES=			tar:xz
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_AUTOPLIST=		yes
PYDISTUTILS_INSTALLARGS+=	--install-lib ${PYTHONPREFIX_LIBDIR}/lib-dynload

DIST_SUBDIR=	python
DISTINFO_FILE=	${PORTSDIR}/lang/python${PYTHON_SUFFIX}/distinfo
WRKSRC=		${WRKDIR}/Python-${PORTVERSION}/Modules

.include <bsd.port.pre.mk>

post-extract:
.if ${PYTHON_REL} < 300
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}
.else
	@${CP} ${FILESDIR}/setup3.py ${WRKSRC}/setup.py
.endif

.include <bsd.port.post.mk>
