# New ports collection makefile for:	files except executables for mule 2.3@19.34
# Version required:	2.3@19.34
# Date created:		7 July 1997
# Whom:			Satoshi Taoka <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id: Makefile,v 1.32 1998/10/07 21:57:56 asami Exp $
#

DISTNAME=	mule-2.3
PKGNAME=	mule-common-2.3
CATEGORIES=	editors japanese
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://ftp.mei.co.jp/archive/free/gnu/emacs/Mule/ \
		ftp://ftp.iij.ad.jp/pub/misc/mule/ \
		http://www.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/mule/
DISTFILES=	emacs-19.34b.tar.gz mule-2.3-19.34.patch-981002.tar.gz

PATCH_SITES=	ftp://etlport.etl.go.jp/pub/mule/
PATCHFILES=	mule-23-1934-alpha01.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

.for dir in 	chinese/mule-wnn4 \
		editors/mule \
		japanese/mule-canna+sj3+wnn4 \
		japanese/mule-canna+sj3+wnn6 \
		japanese/mule-canna+sj3 \
		japanese/mule-canna+wnn4 \
		japanese/mule-canna+wnn6 \
		japanese/mule-canna \
		japanese/mule-sj3+wnn4 \
		japanese/mule-sj3+wnn6 \
		japanese/mule-sj3 \
		japanese/mule-wnn4 \
		japanese/mule-wnn6 \
		korean/mule-wnn4
.if exists(${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work/.install_done)
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work
.elif exists(${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work/.build_done)
WRKDIR?=	${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work
.endif
.endfor
WRKSRC= ${WRKDIR}/emacs-19.34
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/mule.sh

.if !defined(WRKDIR) && !defined(PACKAGE_BUILDING)
BROKEN=		You should build install one of the other mule ports first
.endif

INSTALL_COOKIE=	${WRKDIR}/.install_done-${PKGNAME}
PACKAGE_COOKIE=	${WRKDIR}/.package_done-${PKGNAME}
TMPPLIST=	${WRKDIR}/.PLIST.mktmp-${PKGNAME}
PLIST_SUB=	EMACS_VERSION=19.34

USE_GMAKE=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
EMACS_PREFIX=	mule
EMACS_EXECUTABLE =	mule
CONFIGURE_ARGS=	i386--freebsd --with-executable=${EMACS_EXECUTABLE} \
		--with-emacs-prefix=${EMACS_PREFIX} \
		--with-terminal-face \
		--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib \
STRIP=
MAN1=		coco.1 ctags.1 etags.1 m2ps.1 emacs.1 mule.1

INSTALL_TARGET=	install-arch-indep

post-extract:
	${CP} ${FILESDIR}/unexfreebsd.c ${WRKSRC}/src

pre-build:
	find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	${RM} -f ${WRKSRC}/etc/DOC* ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-19.34.*

post-install:
# note that any2ps rcs-checkin are scripts
.for file in b2m coco ctags emacsclient etags m2ps
	strip ${PREFIX}/bin/${file}
.endfor
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	if [ ! -f ${PREFIX}/share/mule/19.34/info/dir ]; then \
	  ${MKDIR} ${PREFIX}/share/mule/19.34/info; \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/share/mule/19.34/info/dir; \
	fi
.for info in emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message
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
	if [ ! -f ${STARTUP_SCRIPT} ]; then \
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file."; \
		${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT}; \
		${ECHO} '#echo -n " Mule"' >> ${STARTUP_SCRIPT}; \
		${ECHO} 'if [ -d /var/run/emacs/lock ]; then' >> ${STARTUP_SCRIPT}; \
		${ECHO} '     rm -f /var/run/emacs/lock/*' >> ${STARTUP_SCRIPT}; \
		${ECHO} "else" >> ${STARTUP_SCRIPT}; \
		${ECHO} "     mkdir -p /var/run/emacs/lock" >> ${STARTUP_SCRIPT}; \
		${ECHO} "fi" >> ${STARTUP_SCRIPT} ; \
		${ECHO} "chmod 1777 /var/run/emacs/lock${lockdir}" >> ${STARTUP_SCRIPT} ; \
		chmod 755 ${STARTUP_SCRIPT} ;				\
		chown bin.bin ${STARTUP_SCRIPT};			\
	fi

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

.include <bsd.port.mk>
