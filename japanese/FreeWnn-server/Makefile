# New ports collection makefile for:	Wnn for Japanese
# Version required:	4.2
# Date created:		20 July 1997
# Whom:			Satoshi Taoka <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id: Makefile,v 1.20 1998/10/04 12:54:11 kuriyama Exp $
#

DISTNAME=	Wnn4.2
PKGNAME?=	ja-Wnn-4.2
CATEGORIES?=	japanese
MASTER_SITES=	ftp://ftp.u-tokyo.ac.jp/pub/Japanese/Wnn/ \
		ftp://ports.jp.FreeBSD.org/pub/incoming/distfiles/
DISTFILES=	Wnn4.2.tar.gz Wnn4.2.patch.tar.gz

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

BUILD_DEPENDS=	imake:${PORTSDIR}/x11/XFree86

EXTRACT_ONLY=	Wnn4.2.tar.gz
PATCHDIR=	${.CURDIR}/../../japanese/Wnn/patches
FILESDIR=	${.CURDIR}/../../japanese/Wnn/files
PKGDIR=		${.CURDIR}/../../japanese/Wnn/pkg
WRKSRC=		${WRKDIR}/Xsi

.if (${PKGNAME} == ja-Wnn-4.2)
PORT_DOCDIR=	${PREFIX}/share/doc/ja-Wnn
DOC_FROM=	${WRKSRC}/Wnn
.elif (${PKGNAME} == zh-Wnn-4.2)
PORT_DOCDIR=	${PREFIX}/share/doc/zh-Wnn
DOC_FROM=	${WRKSRC}/cWnn
.endif  # kWnn has no manual.

post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/Wnn4.2.patch.tar.gz ${EXTRACT_AFTER_ARGS} \
		-C ${WRKSRC}
	${LN} -sf Project.tmpl ${WRKSRC}/config/X11.tmpl

pre-patch:
	cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < ${WRKSRC}/Wnn4.2.patch

# Applying a patch for depending on language
post-patch:
	case ${PKGNAME} in \
	  ja-Wnn-4.2) \
		LANG_PATCH=${FILESDIR}/patch-for-japanese;; \
	  zh-Wnn-4.2) \
		LANG_PATCH=${FILESDIR}/patch-for-chinese;; \
	  ko-Wnn-4.2) \
		LANG_PATCH=${FILESDIR}/patch-for-korean;; \
	esac; \
	(cd ${_DISTDIR}; \
		${PATCH} ${PATCH_DIST_ARGS} < $${LANG_PATCH})

# for PREFIX
pre-build:
	for file in ${WRKSRC}/config/Project.tmpl \
		${WRKSRC}/Contrib/dic/gerodic/Makefile; do \
	  ${MV} $$file $$file.orig2; \
	  ${SED} 's!^\([ ]*PREFIX = \).*$$!\1${PREFIX}!' \
		$$file.orig2 > $$file; \
	done

# These are necesary because this package uses a different Makefile for
#  building and installing etc.
do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} Makefile.inst World)

pre-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

post-install:
# This package uses imake's "install.man" target to install man pages but
#  I can't define USE_IMAKE because it doesn't involve xmkmf
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
.if defined(PORT_DOCDIR)
	${MKDIR} ${PORT_DOCDIR}
	@(cd ${DOC_FROM}; tar cvf - manual manual.en | \
		(cd ${PORT_DOCDIR}; tar xf -))
	@chown -R bin.bin ${PORT_DOCDIR}
.endif
.endif

.include <bsd.port.mk>
