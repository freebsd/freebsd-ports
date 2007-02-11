# New ports collection makefile for:	eterm
# Date created:        11th December 1998
# Whom:                MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

CATEGORIES=	japanese

MASTERDIR=      ${.CURDIR}/../../x11/eterm

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	X11 terminal emulator based on rxvt/xterm that supports Japanese

EXTRA_PATCHES=	${.CURDIR}/files/extra-patch-configure \
		${.CURDIR}/files/extra-patch-src:command.c \
		${.CURDIR}/files/extra-patch-src:defaultfont.h \
		${.CURDIR}/files/extra-patch-src:feature.h

CONFIGURE_ARGS=	--enable-trans --enable-utmp \
		--enable-xim --with-theme-update \
		--with-backspace=bs --without-terminfo \
		--enable-multi-charset=kanji

PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist

THEMES=		Escreen Eterm auto trans

pre-configure:
	@${REINPLACE_CMD} -e "s,echo aout,echo elf,g" ${WRKSRC}/configure

post-configure:
	for theme in ${THEMES} ; do \
		${CP} ${WRKSRC}/themes/$$theme/theme.cfg ${WRKSRC}/themes/$$theme/theme.cfg.bak ; \
		${SED} -e "s,term_name xterm-color,term_name kterm," < ${WRKSRC}/themes/$$theme/theme.cfg.bak > ${WRKSRC}/themes/$$theme/theme.cfg ; \
		${RM} ${WRKSRC}/themes/$$theme/theme.cfg.bak ; \
	done

.include "${MASTERDIR}/Makefile"
