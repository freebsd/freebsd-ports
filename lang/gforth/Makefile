# New ports collection makefile for:	gforth
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	gforth
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gforth

MAINTAINER=	cyrille.lefevre@laposte.net
COMMENT=	Fast and portable Forth system

# BROKEN=	0.6.2 runtime does Segmentation Fault at compilation time !
#		so, no update is planned right now... sorry.

#ONLY_FOR_ARCHS=	i386 amd64 ia64

# Global variables
#

STRIP=		#none
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CFLAGS=${CFLAGS:N-O*:N-f*}
MAKE_ENV=	CFLAGS=${CFLAGS:N-O*:N-f*}
ALL_TARGET=	all info
PLIST_SUB=	PORTVERSION="${PORTVERSION}" \
		EMACS_DIR="${EMACS_DIR:S,^${PREFIX}/,,}" \
		FORTH_DIR="${FORTH_DIR:S,^${PREFIX}/,,}" \
		LIB_DIR="${LIB_DIR:S,^${PREFIX}/,,}" \
		WORDSIZE=${WORDSIZE} BYTEORDER=${BYTEORDER}

MAN1=		gforth.1

# Local variables
#

.if ${MACHINE_ARCH} == i386
WORDSIZE=32
.else
WORDSIZE=64
.endif

.if ${MACHINE_ARCH} == sparc64
BYTEORDER=b
.else
BYTEORDER=l
.endif

DOC_FILES=	AUTHORS BUGS Benchres COPYING COPYING.DOC \
		INSTALL INSTALL.BINDIST NEWS README \
		NEWS.vmgen README.vmgen ToDo

LIB_DIR=	${PREFIX}/lib/${PKGBASE}

EMACS_FILES=	gforth.el
EMACS_DIR=	${PREFIX}/share/emacs/site-lisp

EMPTY_FILES=	siteinit.fs
FORTH_DIR=	${DATADIR}/site-forth

EMPTY_DIRS=	generic hppa ia64 m68k power sparc
EMPTY_DIRS+=	4stack 6502 8086 avr c165 h8 misc sharc shboom
ARCH_DIR=	${DATADIR}/${PORTVERSION}/arch

# Post-extract
#

post-extract: remove-info-files

remove-info-files:
	@${RM} -f ${WRKSRC}/doc/*.info*

# Post-patch
#

post-patch: patch-makefiles

patch-makefiles:
	@${REINPLACE_CMD} -e 's|makeinfo|makeinfo --no-split|g' \
		${WRKSRC}/Makefile.in

#
# Post-install
#

post-install: install-doc install-el remove-empty-files remove-empty-dirs

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for filename in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${filename} ${DOCSDIR}
.endfor
.endif

install-el:
.for filename in ${EMACS_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${filename} ${EMACS_DIR}
.endfor

remove-empty-files:
.for filename in ${EMPTY_FILES}
	@${RM} -f ${FORTH_DIR}/${filename}
.endfor

remove-empty-dirs:
.for dir in ${EMPTY_DIRS}
	@${RMDIR} ${ARCH_DIR}/${dir}
.endfor

.include <bsd.port.mk>

CONFIGURE_TARGET:=	--build=${CONFIGURE_TARGET}
