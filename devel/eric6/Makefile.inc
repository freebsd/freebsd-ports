# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$
#
# This is a set of Makefile macros which allow to build the core and
# localized language packages for devel/eric6:
# french/eric6, german/eric6, russian/eric6

PORTNAME=	eric6
PORTVERSION=	6.1.6
MASTER_SITES=	SF/eric-ide/${PORTNAME}/stable/${PORTVERSION}
DISTNAME?=	${PORTNAME}-i18n-${I18N_LANG}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER?=	bsam@FreeBSD.org
COMMENT=	Full featured Python and Ruby editor and IDE based on Qt4

LICENSE=	GPLv3

RUN_DEPENDS?=	${PREFIX}/bin/eric6:devel/eric6

I18N_LANG?=	ru
INSTALL_CMD?=	install-i18n.py -p ${STAGEDIR}
MAKE_ENV+=	"HOME=${WRKDIR}"

USES+=		python:2
NO_BUILD=	yes
PLIST_FILES?=	%%DATADIR%%/i18n/${PORTNAME}_${I18N_LANG}.qm
EXTRA_PATCHES?=	${.CURDIR}/../../devel/eric6/files/extra-patch-install-i18n.py

.if ! defined(MASTERPORT)
NO_ARCH=	yes
.endif

do-install:
	@(cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_CMD})

DESCR=		${.CURDIR}/../../devel/eric6/pkg-descr

.include <bsd.port.mk>
