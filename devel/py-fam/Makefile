PORTNAME=	fam
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	SF/python-${PORTNAME}/python-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-fam-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python Interface to the File Alteration Monitor
WWW=		https://python-fam.sourceforge.net/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfam.so.0:devel/gamin

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

pre-patch:
	${INSTALL_DATA} ${FILESDIR}/setup.py ${WRKSRC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_fam*.so

.include <bsd.port.mk>
