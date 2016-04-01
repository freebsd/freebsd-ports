# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
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

LIB_DEPENDS=	libanthy.so:japanese/anthy \
		libuim.so:textproc/uim

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
	(cd ${WRKSRC}/uim && ${MAKE_CMD} libuim-anthy.la)
	(cd ${WRKSRC}/uim && ${MAKE_CMD} libuim-anthy-utf8.la)
.if !defined(WITHOUT_X11)
	(cd ${WRKSRC}/gtk2/dict && ${MAKE_CMD} uim-dict-gtk)
.endif

do-install:
	(cd ${WRKSRC}/uim && \
	${MAKE_CMD} DESTDIR=${STAGEDIR} uim_plugin_LTLIBRARIES=libuim-anthy.la install-uim_pluginLTLIBRARIES && \
	${MAKE_CMD} DESTDIR=${STAGEDIR} uim_plugin_LTLIBRARIES=libuim-anthy-utf8.la install-uim_pluginLTLIBRARIES)
.if !defined(WITHOUT_X11)
	(cd ${WRKSRC}/gtk2/dict && ${MAKE_CMD} DESTDIR=${STAGEDIR} bin_PROGRAMS=uim-dict-gtk install-binPROGRAMS install-uim_dict_uiDATA)
.endif

.include "${MASTERDIR}/Makefile"
