# New ports collection makefile for:	eterm
# Date created:        24th December 2000
# Whom:                Michael C. Wu
# $FreeBSD$

CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../x11/eterm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 terminal emulator based on rxvt/xterm that supports traditional Chinese (Big5)

EXTRA_PATCHES=	${.CURDIR}/files/extra-patch-configure.in

CONFIGURE_ARGS=	--enable-trans --enable-utmp \
		--enable-xim --with-theme-update \
		--with-backspace=bs --without-terminfo \
		--enable-multi-charset=big5

PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/kc15f.pcf.gz:${PORTSDIR}/chinese/kcfonts

.include "${MASTERDIR}/Makefile"
