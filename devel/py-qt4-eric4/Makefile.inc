# This is a set of Makefile macros which allow to build the core and
# localized language packages for devel/py-qt4-eric4. Look at
# german/de-py-qt4-eric4 for an example.
#
# Date created:				23 Apr 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eric4
PORTVERSION=	4.0.a${SNAPSHOT}
MASTER_SITES=	http://www.die-offenbachs.de/detlev/snapshots4/
PKGNAMEPREFIX?=	${I18N_LANG}-${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME?=	${PORTNAME}-i18n-${I18N_LANG}-snapshot-${SNAPSHOT}
WRKSRC=		${WRKDIR}/${PORTNAME}-snapshot-${SNAPSHOT}

MAINTAINER?=	bsam@FreeBSD.org
COMMENT=	Full featured Python and Ruby editor and IDE based on Qt4

RUN_DEPENDS?=	${PREFIX}/bin/eric4:${PORTSDIR}/devel/py-qt4-eric4

SNAPSHOT=	20070411
I18N_LANG?=	ru
INSTALL_CMD?=	install-i18n.py

USE_PYTHON=	2.4+
NO_BUILD=	yes
DOCSDIR=	${TARGETDIR}/share/doc/py-qt4-${PORTNAME}
PLIST_FILES?=	%%PYTHON_SITELIBDIR%%/${PORTNAME}/${PORTNAME}_${I18N_LANG}.qm

do-install:
	@(cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_CMD})

DESCR=		${.CURDIR}/../../devel/py-qt4-eric4/pkg-descr

.include <bsd.port.mk>
