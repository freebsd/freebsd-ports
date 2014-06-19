# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

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

LIB_DEPENDS=	libanthy.so:${PORTSDIR}/japanese/anthy \
		libuim.so:${PORTSDIR}/textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-anthy --with-anthy-utf8

.if !defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--with-gtk2 --enable-dict
.endif

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-uim_Makefile.in \
		${PATCHDIR}/extra-patch-gtk2_dict_Makefile.in

do-build:
	(cd ${WRKSRC}/uim && ${GMAKE} libuim-anthy.la)
	(cd ${WRKSRC}/uim && ${GMAKE} libuim-anthy-utf8.la)
.if !defined(WITHOUT_X11)
	(cd ${WRKSRC}/gtk2/dict && ${GMAKE} uim-dict-gtk)
.endif

do-install:
	(cd ${WRKSRC}/uim && \
	${GMAKE} DESTDIR=${STAGEDIR} uim_plugin_LTLIBRARIES=libuim-anthy.la install-uim_pluginLTLIBRARIES && \
	${GMAKE} DESTDIR=${STAGEDIR} uim_plugin_LTLIBRARIES=libuim-anthy-utf8.la install-uim_pluginLTLIBRARIES)
.if !defined(WITHOUT_X11)
	(cd ${WRKSRC}/gtk2/dict && ${GMAKE} DESTDIR=${STAGEDIR} bin_PROGRAMS=uim-dict-gtk install-binPROGRAMS install-uim_dict_uiDATA)
.endif

.include "${MASTERDIR}/Makefile"
