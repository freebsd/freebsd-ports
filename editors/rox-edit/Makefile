# Ports collection Makefile for:	rox-edit
# Date created:				Jan 13 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rox-edit
PORTVERSION=	1.9.7
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=	edit-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Text editor for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
		${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:${PORTSDIR}/devel/py-roxlib

USE_PYTHON=	yes

post-extract:
	@${FIND} ${WRKSRC} -name .cvsignore | ${XARGS} ${RM}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/apps
	@${CP} -r ${WRKSRC}/Edit ${PREFIX}/apps/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/apps/Edit

.include <bsd.port.mk>
