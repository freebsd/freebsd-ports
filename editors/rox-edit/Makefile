# Ports collection Makefile for:	rox-edit
# Date created:				Jan 13 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rox-edit
PORTVERSION=	2.1
CATEGORIES=	editors
MASTER_SITES=	SF/rox/Edit/${PORTVERSION}
DISTNAME=	edit-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Text editor for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
		${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:${PORTSDIR}/devel/py-roxlib

USE_PYTHON=	yes
USE_BZIP2=	yes

post-extract:
	@${FIND} ${WRKSRC} -name .cvsignore | ${XARGS} ${RM}
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/apps
	@${CP} -r ${WRKSRC}/Edit ${PREFIX}/apps/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/apps/Edit

.include <bsd.port.mk>
