# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$
#
# This is a set of Makefile macros which allow to build the core and
# localized language packages for devel/eric6:
# french/eric6, german/eric6, russian/eric6

PORTNAME=	eric6
PORTVERSION=	6.1.11
MASTER_SITES=	SF/eric-ide/${PORTNAME}/stable/${PORTVERSION}
DISTNAME?=	${PORTNAME}-i18n-${I18N_LANG}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER?=	dbn@FreeBSD.org
COMMENT=	Full featured Python and Ruby editor and IDE based on Qt

LICENSE=	GPLv3

RUN_DEPENDS?=	${LOCALBASE}/bin/eric6:devel/eric6

I18N_LANG?=	ru
INSTALL_CMD?=	install-i18n.py -p ${STAGEDIR}
MAKE_ENV+=	"HOME=${WRKDIR}"

USES+=		python
NO_BUILD=	yes
PLIST_FILES?=	%%DATADIR%%/i18n/${PORTNAME}_${I18N_LANG}.qm
EXTRA_PATCHES?=	${.CURDIR}/../../devel/eric6/files/extra-patch-install-i18n.py

.if ! defined(MASTERPORT)
NO_ARCH=	yes
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} <= 2.7
PLIST_SUB+=	PYTHON2=
.else
PLIST_SUB+=	PYTHON2="@comment "
.endif

do-install:
	@(cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_CMD})

DESCR=		${.CURDIR}/../../devel/eric6/pkg-descr

.include <bsd.port.post.mk>
