# New ports collection makefile for:   ja-uim-canna
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese
PKGNAMESUFFIX=	-canna

COMMENT=	Uim plugin using Canna input method

RUN_DEPENDS=	uim-module-manager:${PORTSDIR}/textproc/uim
LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-canna

UIM_SLAVE=	yes

do-install:
	cd ${WRKSRC}/uim && \
	${GMAKE} uim_plugin_LTLIBRARIES=libuim-canna.la install-uim_pluginLTLIBRARIES

post-install:
	uim-module-manager --register canna

.include "${MASTERDIR}/Makefile"
