# New ports collection makefile for:	gforth
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	gforth
PORTVERSION=	0.6.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gforth

MAINTAINER=	cyrille.lefevre@laposte.net
COMMENT=	Fast and portable Forth system

# Global variables
#

STRIP=		#none
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	all info
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

MAN1=		gforth.1

# Local variables
#

DOC_FILES=	AUTHORS BUGS Benchres COPYING COPYING.DOC \
		INSTALL INSTALL.BINDIST NEWS README \
		NEWS.vmgen README.vmgen ToDo

EMACS_FILES=	gforth.el
EMACS_DIR=	${PREFIX}/share/emacs/site-lisp

EMPTY_FILES=	siteinit.fs
FORTH_DIR=	${DATADIR}/site-forth

EMPTY_DIRS=	4stack 6502 8086 avr c165 generic h8 hppa \
		ia64 m68k misc power sharc shboom sparc
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
.if !defined(NOPORTSDOC)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

install-el:
.for file in ${EMACS_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${EMACS_DIR}
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

CONFIGURE_TARGET:=	--build=${CONFIGURE_TARGET}
