# Ports collection Makefile for:	py-roxlib
# Date created:				Jan 12 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		roxlib
PORTVERSION=		1.9.12
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		rox-lib-${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=		olgeni@FreeBSD.org
COMMENT=		Python libraries for ROX

USE_PYTHON=		yes

RUN_DEPENDS=		${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
			${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@cd ${WRKSRC}/ROX-Lib2/python && ${PYTHON_CMD} make_docs.py

do-install:
	@${CP} -r ${WRKSRC}/ROX-Lib2 ${PREFIX}/lib
        @${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/ROX-Lib2

.include <bsd.port.mk>
