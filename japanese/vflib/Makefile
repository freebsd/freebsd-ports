# New ports collection makefile for:	vflib + FreeType
# Version required:	2.22 Patchlevel 10
# Date created:		10 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.12 1998/03/20 14:54:43 itojun Exp $
#

DISTNAME=	VFlib-2.22-PL8
PKGNAME=	ja-vflib-2.22.10
CATEGORIES=	japanese print
MASTER_SITES=	ftp://gull.se.hiroshima-u.ac.jp/pub/VFlib/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} watanabe-vf.tar.Z

PATCH_SITES=	http://itohws03.ee.noda.sut.ac.jp/~matsuda/VFlib-FT/ \
		${MASTER_SITES}
PATCHFILES=	VFlib-2.22-Patch9 VFlib-2.22-Patch10 VFlib-FT1.0-PL2.diff.gz

MAINTAINER=	mita@jp.FreeBSD.org

LIB_DEPENDS=	ttf\\.1\\.0:${PORTSDIR}/print/freetype

BROKEN=		left behind by freetype upgrade

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/VFlib-2.22pl8
MAKE_ENV=	PREFIX=${PREFIX} FREETYPEINCDIR=${FREETYPEINCDIR} \
		FREETYPELIBDIR=${FREETYPELIBDIR}
FREETYPEINCDIR=	${PREFIX}/include
FREETYPELIBDIR=	${PREFIX}/lib

do-patch:
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
	@${CAT} ${DISTDIR}/VFlib-2.22-Patch9 ${DISTDIR}/VFlib-2.22-Patch10 | \
		${PATCH} ${PATCH_DIST_ARGS:S/${WRKSRC}/&\/src/}
	@${GZCAT} ${DISTDIR}/VFlib-FT1.0-PL2.diff.gz | ${PATCH} ${PATCH_DIST_ARGS}
	@if [ "`echo ${PATCHDIR}/patch-*`" = "${PATCHDIR}/patch-*" ]; then \
		${ECHO_MSG} "===>   Ignoring empty patch directory"; \
	else \
		${ECHO_MSG} "===>  Applying ${OPSYS} patches for ${PKGNAME}" ; \
		for i in ${PATCHDIR}/patch-*; do \
			case $$i in \
				*.orig|*.rej|*~) \
					${ECHO_MSG} "===>   Ignoring patchfile $$i" ; \
					;; \
				*) \
					${PATCH} ${PATCH_ARGS} < $$i; \
					;; \
			esac; \
		done; \
	fi;

do-build:
	@(cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC}/tools; ${XMKMF}; ${SETENV} ${MAKE_ENV} ${MAKE})

do-install:
	${MKDIR} ${PREFIX}/lib/VFlib
	@(cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET})
	@(cd ${WRKSRC}/tools; \
	  ${INSTALL_PROGRAM} fmtest disol kban ktest vfperf vftest \
	    ${PREFIX}/lib/VFlib)
	@(cd ${WRKSRC}; \
	  ${CP} -R doc jTeX COPYING README.txt.JP_EUC vfontcap \
	    vfontcap.bdf vfontcap.comp2 ${PREFIX}/lib/VFlib)
	${MKDIR} ${PREFIX}/share/fonts/watanabe_font
	tar -C ${PREFIX}/share/fonts/watanabe_font \
	  -xzf ${DISTDIR}/watanabe-vf.tar.Z
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
