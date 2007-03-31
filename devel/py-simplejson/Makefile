# New ports collection makefile for:	py-simplejson
# Date created:				25 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	simplejson
PORTVERSION=	1.7.1
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/s/simplejson/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Simplejson is a simple, fast, extensible JSON encoder/decoder

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYSIMPLEJSON_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}-freebsd-${OSRELEASE}-${ARCH}.egg

PLIST_SUB+=	PYSIMPLEJSON_EGG=${PYSIMPLEJSON_EGG} \
		EGG_VER="${PORTNAME}==${PORTVERSION}"

.if !defined(NOPORTDOCS)
DOCSDIR=	${TARGETDIR}/share/doc/py-${PORTNAME}
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

OSRELEASE!=	uname -r

.include <bsd.port.post.mk>
