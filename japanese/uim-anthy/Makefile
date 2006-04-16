# New ports collection makefile for:   ja-uim-anthy
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese
PKGNAMESUFFIX=	-anthy

COMMENT=	Uim plugin using Anthy input method

RUN_DEPENDS=	uim-module-manager:${PORTSDIR}/textproc/uim
LIB_DEPENDS=	anthy.1:${PORTSDIR}/japanese/anthy

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-anthy

UIM_SLAVE=	yes

do-install:
	cd ${WRKSRC}/uim && \
	${GMAKE} uim_plugin_LTLIBRARIES=libuim-anthy.la install-uim_pluginLTLIBRARIES

post-install:
	uim-module-manager --register anthy

.include "${MASTERDIR}/Makefile"
