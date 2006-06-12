# New ports collection makefile for:   ja-uim-anthy
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese
PKGNAMESUFFIX=	-anthy

COMMENT=	Uim plugin using Anthy input method

USE_GNOME=	gtk20

RUN_DEPENDS=	uim-module-manager:${PORTSDIR}/textproc/uim
LIB_DEPENDS=	anthy.1:${PORTSDIR}/japanese/anthy

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-anthy --with-gtk2 --enable-dict

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-uim_Makefile.in \
		${PATCHDIR}/extra-patch-helper_Makefile.in

do-build:
	(cd ${WRKSRC}/uim && ${GMAKE} libuim-anthy.la)
	(cd ${WRKSRC}/helper && ${GMAKE} LIBS="-luim" uim-dict-gtk)

do-install:
	(cd ${WRKSRC}/uim && \
	${GMAKE} uim_plugin_LTLIBRARIES=libuim-anthy.la install-uim_pluginLTLIBRARIES)
	(cd ${WRKSRC}/helper && ${GMAKE} bin_PROGRAMS=uim-dict-gtk install-binPROGRAMS)

post-install:
	${X11BASE}/bin/uim-module-manager --register anthy

.include "${MASTERDIR}/Makefile"
