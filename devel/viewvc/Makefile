# New ports collection makefile for:	viewcvs
# Date created:				Sun 02 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	viewvc
PORTVERSION=	1.0.4
CATEGORIES=	devel python
MASTER_SITES=	http://viewvc.tigris.org/files/documents/3330/37319/

MAINTAINER=	jbq@caraldi.com
COMMENT=	Web-based Version Control Repository Browsing

RUN_DEPENDS=	${PYTHON_LIBDIR}/site-packages/svn/__init__.py:${PORTSDIR}/devel/subversion-python

USE_PYTHON=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	INSTDIR="${PREFIX}/${INSTDIR}"

INSTDIR?=	${PORTNAME}
PLIST_SUB=	INSTDIR=${INSTDIR}

do-install:
	(cd ${WRKSRC} && ${PYTHON_CMD} viewvc-install --prefix=${PREFIX}/${INSTDIR} --destdir="" --clean-mode=false)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
