# New ports collection makefile for:   ja-uim-prime
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese
.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-prime-nox11
.else
PKGNAMESUFFIX=	-prime
.endif

COMMENT=	Uim plugin using PRIME input method

BUILD_DEPENDS=	prime:${PORTSDIR}/japanese/prime
LIB_DEPENDS=	uim.6:${PORTSDIR}/textproc/uim
RUN_DEPENDS+=	${BUILD_DEPENDS}

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-prime

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-uim_Makefile.in

do-build:
	(cd ${WRKSRC}/uim && ${GMAKE} libuim-prime.la)

do-install:
	(cd ${WRKSRC}/uim && \
	${GMAKE} uim_plugin_LTLIBRARIES=libuim-prime.la install-uim_pluginLTLIBRARIES)

post-install:
	${LOCALBASE}/bin/uim-module-manager --register prime

.include "${MASTERDIR}/Makefile"
