# New ports collection makefile for:	jp-groff
# Version required:	1.09+0.98
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id$
#

DISTNAME=	groff-1.09
PKGNAME=	jp-groff-0.98
CATEGORIES=	japanese printing
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

MAINTAINER=	asami@FreeBSD.ORG

PATCH_SITES=	ftp://ftp.iij.ad.jp/pub/NetNews/fj.sources/volume95/Apr/
PATCHFILES=	jgroff-0.98.diff.gz
DISTPATCHES=	950414.01.Z 950414.02.Z
PATCH_DIST_STRIP=	-p1

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=/usr/local

EXTRANAME=	jp-gxditview-0.98
EXTPKGFILE=	$(EXTRANAME)$(PKG_SUFX)

PRECONFIGURE_COOKIE=	${.CURDIR}/work/.preconfigure_done
PREBUILD_COOKIE=	${.CURDIR}/work/.prebuild_done
PREINSTALL_COOKIE=	${.CURDIR}/work/.preinstall_done
EXTRASRC=		${WRKDIR}/${DISTNAME}/xditview
EXTPKG=			${.CURDIR}/pkg.gxditview
EXT_PKG_ARGS=		-v -c ${EXTPKG}/COMMENT -d ${EXTPKG}/DESCR -f ${EXTPKG}/PLIST -p ${X11BASE}

pre-fetch: 
	@(cd ${DISTDIR}; \
	 if [ ! -f ${PATCHFILES} ]; then \
	    ${ECHO_MSG} ">> ${PATCHFILES} doesn't seem to exist on this system."; \
	    for file in ${DISTPATCHES} ; do \
		for site in ${PATCH_SITES} ; do \
		    if ${NCFTP} ${NCFTPFLAGS} $${site}$${file}; then \
			break; \
		    fi \
		done; \
	    done; \
	    for file in ${DISTPATCHES} ; do zcat $${file}; done | \
		sed '/^END -----/,/^BEGIN ----/d' | uudecode; \
	    rm -f ${DISTPATCHES};\
	 fi)

pre-configure: $(PRECONFIGURE_COOKIE)

$(PRECONFIGURE_COOKIE):
	@${ECHO_MSG} "===>  Configuring for ${EXTRANAME}"
	@(cd ${EXTRASRC}; ${XMKMF} && ${MAKE} Makefiles)
	@${TOUCH} ${TOUCH_FLAGS} ${PRECONFIGURE_COOKIE}

pre-build: $(PREBUILD_COOKIE)

$(PREBUILD_COOKIE):
	@${ECHO_MSG} "===>  Building for ${EXTRANAME}"
	@(cd ${EXTRASRC}; ${MAKE} PREFIX=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})
	@${TOUCH} ${TOUCH_FLAGS} $(PREBUILD_COOKIE)

pre-install: $(PREINSTALL_COOKIE)

$(PREINSTALL_COOKIE):
	@${ECHO_MSG} "===>  Installing for ${EXTRANAME}"
	@(cd ${EXTRASRC}; ${MAKE} PREFIX=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	@(cd ${EXTRASRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)
	@${TOUCH} ${TOUCH_FLAGS} ${PREINSTALL_COOKIE}

# pre-package disabled for now
tmp-pre-package:
	@if [ -d ${PKGDIR} ]; then \
		${ECHO_MSG} "===>  Building package for ${EXTRANAME}"; \
		${PKG_CMD} ${EXT_PKG_ARGS} ${EXTPKGFILE}; \
	fi

.include <bsd.port.mk>
