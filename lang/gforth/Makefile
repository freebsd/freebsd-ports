# New ports collection makefile for:	gforth
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	gforth
PORTVERSION=	0.5.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gforth

MAINTAINER=	cyrille.lefevre@laposte.net

# Global variables
#

STRIP=		#none

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	all info

# PREFIX isn't honored. force it w/ prefix.
MAKE_ARGS=	prefix=${PREFIX}

MAN1=		gforth.1

# Local variables
#

INSTALL_INFO?=	install-info

INFO_FILES=	${PORTNAME}.info
INFO_DIR=	${PREFIX}/info

EMACS_FILES=	gforth.el
EMACS_DIR=	${PREFIX}/share/emacs/site-lisp

EMPTY_FILES=	siteinit.fs
FORTH_DIR=	${DATADIR}/site-forth

EMPTY_DIRS=	4stack 6502 8086 avr c165 generic h8 \
		hppa ia64 m68k misc power shboom sparc
ARCH_DIR=	${DATADIR}/${PORTVERSION}/arch

# Post-extract
#

post-extract: remove-info-files

remove-info-files:
.for file in ${INFO_FILES}
	@${RM} -f ${WRKSRC}/doc/${file}*
.endfor

# Post-patch
#

post-patch: patch-makefiles

patch-makefiles:
	@${PERL} -pi.fbsd -e 's|makeinfo|makeinfo --no-split|g' \
		${WRKSRC}/Makefile.in

#
# Post-install
#

post-install: install-info install-el \
	      remove-empty-files remove-empty-dirs

install-info:
.for file in ${INFO_FILES}
	@${INSTALL_INFO} ${INFO_DIR}/${file} ${INFO_DIR}/dir
.endfor

install-el:
.for file in ${EMACS_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${EMACS_DIR}/${file}
.endfor

remove-empty-files:
.for file in ${EMPTY_FILES}
	@${RM} -f ${FORTH_DIR}/${file}
.endfor

remove-empty-dirs:
.for dir in ${EMPTY_DIRS}
	@${RMDIR} ${ARCH_DIR}/${dir}
.endfor

.include <bsd.port.mk>
