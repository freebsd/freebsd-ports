# New ports collection makefile for:	files except executables for mule
# Version required:	2.3
# Date created:		7 July 1997
# Whom:			Satoshi Taoka <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id$
#

DISTNAME=	mule-2.3
PKGNAME=	mule-common-2.3
CATEGORIES=	editors chinese japanese korean
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://ftp.mei.co.jp/archive/free/gnu/emacs/Mule/ \
		ftp://ftp.iij.ad.jp/pub/misc/mule/ \
		ftp://ports.jp.FreeBSD.org/pub/incoming/distfiles/
DISTFILES=	mule-2.3.tar.gz mule-2.3.patch-970819.tar.gz

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

EXTRACT_ONLY=	mule-2.3.tar.gz
.for dir in editors/mule japanese/mule-canna japanese/mule-canna+sj3 \
	japanese/mule-canna japanese/mule-canna+sj3 \
	japanese/mule-canna+sj3+wnn4 japanese/mule-canna+sj3+wnn6 \
	japanese/mule-canna+wnn4 japanese/mule-canna+wnn6 \
	japanese/mule-sj3 japanese/mule-sj3+wnn japanese/mule-sj3+wnn6 \
	japanese/mule-wnn4 japanese/mule-wnn6 \
	chinese/mule-wnn4 korean/mule-wnn4
.if exists(${.CURDIR}/../../${dir}/work/.build_done)
WRKDIR?=	${.CURDIR}/../../${dir}/work
.endif
.endfor
WRKSRC= ${WRKDIR}/mule

.if !defined(WRKDIR) && !defined(PACKAGE_BUILDING)
BROKEN=		You should build install one of the other mule ports first
.endif

INSTALL_COOKIE=	${WRKDIR}/.install_done-${PKGNAME}
PACKAGE_COOKIE=	${WRKDIR}/.package_done-${PKGNAME}

USE_GMAKE=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --with-x-toolkit \
		--terminal-face \
		--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib \
		--locallisppath=${PREFIX}/lib/mule/site-lisp:${PREFIX}/share/emacs/site-lisp
STRIP=
MAN1=		coco.1 ctags.1 etags.1 m2ps.1 mule.1

INSTALL_TARGET=	install-arch-indep

post-extract:
	${EXTRACT_CMD} -C ${WRKSRC} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/mule-2.3.patch-970819.tar.gz
	cd ${WRKSRC}; ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ./takana.tar.gz

pre-patch:
	cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < ${WRKSRC}/patch

post-patch:
	cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < ${WRKSRC}/Mule-2.3.patch

pre-build:
	find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	${RM} -f ${WRKSRC}/etc/DOC* ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-19.28.*

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in emacs vip forms gnus cl sc
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
# Our makeinfo can't handle files with Japanese characters. :<
	install-info --section="The Emacs editor and associated tools" --entry="* Antenews-jp: (antenews-jp).	Version 19 Antenews. (Japanese)" ${PREFIX}/info/antenews-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Mule: (mule).			Multilingual Enhancement to GNU Emacs." ${PREFIX}/info/mule ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Mule-jp: (mule-jp).		Multilingual Enhancement to GNU Emacs. (Japanese)" ${PREFIX}/info/mule-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Egg-jp: (egg-jp).		Japanese/Chinese Inputting Method. (Japanese)" ${PREFIX}/info/egg-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Canna-jp: (canna-jp).		Another Japanese Inputting Method. (Japanese)" ${PREFIX}/info/canna-jp ${PREFIX}/info/dir
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

.include <bsd.port.mk>
