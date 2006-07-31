# New ports collection makefile for:   ja-uim-canna
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese
.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-canna-nox11
.else
PKGNAMESUFFIX=	-canna
.endif

COMMENT=	Uim plugin using Canna input method

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna \
		uim.2:${PORTSDIR}/textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-canna

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-uim_Makefile.in

do-build:
	(cd ${WRKSRC}/uim && ${GMAKE} libuim-canna.la)

do-install:
	(cd ${WRKSRC}/uim && \
	${GMAKE} uim_plugin_LTLIBRARIES=libuim-canna.la install-uim_pluginLTLIBRARIES)

post-install:
.if defined(WITHOUT_X11)
	${LOCALBASE}/bin/uim-module-manager --register canna
.else
	${X11BASE}/bin/uim-module-manager --register canna
.endif

.include "${MASTERDIR}/Makefile"
