# New ports collection makefile for:   ja-uim-anthy
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese
.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-anthy-nox11
.else
PKGNAMESUFFIX=	-anthy
.endif

COMMENT=	Uim plugin using Anthy input method

.if !defined(WITHOUT_X11)
USE_GNOME=	gtk20
.endif

LIB_DEPENDS=	anthy.1:${PORTSDIR}/japanese/anthy \
		uim.6:${PORTSDIR}/textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-anthy

.if !defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--with-gtk2 --enable-dict
.endif

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-uim_Makefile.in \
		${PATCHDIR}/extra-patch-helper_Makefile.in

do-build:
	(cd ${WRKSRC}/uim && ${GMAKE} libuim-anthy.la)
.if !defined(WITHOUT_X11)
	(cd ${WRKSRC}/helper && ${GMAKE} uim-dict-gtk)
.endif

do-install:
	(cd ${WRKSRC}/uim && \
	${GMAKE} uim_plugin_LTLIBRARIES=libuim-anthy.la install-uim_pluginLTLIBRARIES)
.if !defined(WITHOUT_X11)
	(cd ${WRKSRC}/helper && ${GMAKE} bin_PROGRAMS=uim-dict-gtk install-binPROGRAMS install-uim_dict_uiDATA)
.endif

post-install:
	${LOCALBASE}/bin/uim-module-manager --register anthy

.include "${MASTERDIR}/Makefile"
