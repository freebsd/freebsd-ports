# This is a set of Makefile macros which allow to build the core and
# localized language packages for devel/eric4:
# french/eric4, german/eric4, russian/eric4
#
# Date created:				23 Apr 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eric4
PORTVERSION=	4.5.5
MASTER_SITES=	SF/eric-ide/${PORTNAME}/stable/${PORTVERSION}
DISTNAME?=	${PORTNAME}-i18n-${I18N_LANG}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER?=	bsam@FreeBSD.org
COMMENT=	Full featured Python and Ruby editor and IDE based on Qt4

LICENSE=	GPLv3

RUN_DEPENDS?=	${PREFIX}/bin/eric4:${PORTSDIR}/devel/eric4

I18N_LANG?=	ru
INSTALL_CMD?=	install-i18n.py

USE_PYTHON=	2.5+
NO_BUILD=	yes
PLIST_FILES?=	%%PYTHON_SITELIBDIR%%/${PORTNAME}/${PORTNAME}_${I18N_LANG}.qm

do-install:
	@(cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_CMD})

DESCR=		${.CURDIR}/../../devel/eric4/pkg-descr

.include <bsd.port.mk>
