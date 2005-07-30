# Ports collection Makefile for:	rox-archive
# Date created:				Mar 24 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		rox-archive
PORTVERSION=		1.9.5
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=		archive-${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=		olgeni@FreeBSD.org
COMMENT=		Archive management tool for the ROX desktop

RUN_DEPENDS=		${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
			${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:${PORTSDIR}/devel/py-roxlib

USE_PYTHON=		yes

post-patch:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -r

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/apps
	@${CP} -r ${WRKSRC}/Archive ${PREFIX}/apps/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/apps/Archive

.include <bsd.port.mk>
