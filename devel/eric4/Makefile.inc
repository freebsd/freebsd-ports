# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$
#
# This is a set of Makefile macros which allow to build the core and
# localized language packages for devel/eric4:
# french/eric4, german/eric4, russian/eric4

PORTNAME=	eric4
PORTVERSION=	4.5.24
MASTER_SITES=	SF/eric-ide/${PORTNAME}/stable/${PORTVERSION}
DISTNAME?=	${PORTNAME}-i18n-${I18N_LANG}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER?=	bsam@FreeBSD.org
COMMENT=	Full featured Python and Ruby editor and IDE based on Qt4

LICENSE=	GPLv3

RUN_DEPENDS?=	${PREFIX}/bin/eric4:devel/eric4

I18N_LANG?=	ru
INSTALL_CMD?=	install-i18n.py -p ${STAGEDIR}
MAKE_ENV+=	"HOME=${WRKDIR}"

USES+=		python:2
NO_BUILD=	yes
PLIST_FILES?=	%%DATADIR%%/i18n/${PORTNAME}_${I18N_LANG}.qm
EXTRA_PATCHES?=	${.CURDIR}/../../devel/eric4/files/extra-patch-install-i18n.py

do-install:
	@(cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_CMD})

DESCR=		${.CURDIR}/../../devel/eric4/pkg-descr

.include <bsd.port.mk>
