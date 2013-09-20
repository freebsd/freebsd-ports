# Created by: Michael C. Wu
# $FreeBSD$

CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../x11/eterm

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	X11 terminal emulator based on rxvt/xterm that supports traditional Chinese (Big5)

EXTRA_PATCHES=	${.CURDIR}/files/extra-patch-configure

CONFIGURE_ARGS=	--enable-trans --enable-utmp \
		--enable-xim --with-theme-update \
		--with-backspace=bs --without-terminfo \
		--enable-multi-charset=big5

PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/local/kc15f.pcf.gz:${PORTSDIR}/chinese/kcfonts

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
