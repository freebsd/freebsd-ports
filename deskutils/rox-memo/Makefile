# Ports collection Makefile for:	rox-memo
# Date created:				Jan 12 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		rox-memo
PORTVERSION=		1.9.5
CATEGORIES=		deskutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=		Memo-${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=		olgeni@FreeBSD.org
COMMENT=		Appointment/TODO management for the ROX desktop

RUN_DEPENDS=		${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
			${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:${PORTSDIR}/devel/py-roxlib

USE_PYTHON=		yes

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/apps
	@${CP} -r ${WRKSRC}/Memo ${PREFIX}/apps/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/apps/Memo

.include <bsd.port.mk>
