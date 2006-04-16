# New ports collection makefile for:   ja-uim-prime
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese
PKGNAMESUFFIX=	-prime

COMMENT=	Uim plugin using PRIME input method

RUN_DEPENDS=	uim-module-manager:${PORTSDIR}/textproc/uim
BUILD_DEPENDS=	prime:${PORTSDIR}/japanese/prime
RUN_DEPENDS+=	${BUILD_DEPENDS}

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-prime

UIM_SLAVE=	yes

do-install:
	cd ${WRKSRC}/uim && \
	${GMAKE} uim_plugin_LTLIBRARIES=libuim-prime.la install-uim_pluginLTLIBRARIES

post-install:
	uim-module-manager --register prime

.include "${MASTERDIR}/Makefile"
