# New ports collection makefile for:    hanIM
# Version required:     1.0
# Date created:         17 Mar 1998
# Whom:                 CHOI Junho <cjh@kr.freebsd.org
#
# $FreeBSD$
#

DISTNAME=       hanIM-${HANIM_VER}-${HANIM_VER_PL}.i386
PKGNAME=        ko-hanIM-${HANIM_VER}
CATEGORIES=     korean x11 linux
MASTER_SITES=   ftp://www.mizi.co.kr/pub/hanIM/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
EXTRACT_SUFX=   .rpm

MAINTAINER=     cjh@kr.freebsd.org

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/misc/rpm
RUN_DEPENDS=	${PREFIX}/lib/X11/fonts/local/mzgt16h1.pcf.gz:${PORTSDIR}/korean/mizifont \
		/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		/compat/linux/usr/share/locale/ko/LC_MESSAGES/SYS_LC_MESSAGES:${PORTSDIR}/korean/linux_locale

NO_CDROM=	"Not a free software"

USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes
STRIP=

RPM2CPIO=	rpm2cpio
CPIO=		/usr/bin/cpio
CPIO_OPT=	-i --make-directories

HANIM_VER=	1.1b
HANIM_VER_PL=	glibc2.0.7-1

do-extract:
	@${RM} -rf ${WRKDIR} && \
	${MKDIR} ${WRKDIR} && \
	cd ${WRKDIR} && \
	${RPM2CPIO} ${_DISTDIR}/${DISTFILES} | ${CPIO} ${CPIO_OPT}

do-build:
	# documents & samples
	${RM} ${WRKDIR}/usr/doc/hanIM-${HANIM_VER}/samples/*.orig
	# dirty workaround. you should delete compiled garbages!
	${RM} ${WRKDIR}/usr/doc/hanIM-${HANIM_VER}/samples/.#* \
	      ${WRKDIR}/usr/doc/hanIM-${HANIM_VER}/samples/*.o \
	      ${WRKDIR}/usr/doc/hanIM-${HANIM_VER}/samples/asample \
	      ${WRKDIR}/usr/doc/hanIM-${HANIM_VER}/samples/overspot \
	      ${WRKDIR}/usr/doc/hanIM-${HANIM_VER}/samples/rootwin

do-install:
	# binary
	${INSTALL_PROGRAM} ${WRKDIR}/usr/X11R6/bin/hanIM ${PREFIX}/bin/

	# application defaults
	${INSTALL_DATA} ${WRKDIR}/usr/X11R6/lib/X11/app-defaults/HanIM \
		${PREFIX}/lib/X11/app-defaults/

	# help files
	${MKDIR} ${PREFIX}/lib/X11/hanIM/help
	${INSTALL_DATA} ${WRKDIR}/usr/X11R6/lib/X11/hanIM/*.tbl \
		${PREFIX}/lib/X11/hanIM/
	${INSTALL_DATA} ${WRKDIR}/usr/X11R6/lib/X11/hanIM/help/* \
		${PREFIX}/lib/X11/hanIM/help/

	# documents & samples
	${MKDIR} ${PREFIX}/share/doc/hanIM
	${CP} -r ${WRKDIR}/usr/doc/hanIM-${HANIM_VER}/* \
		${PREFIX}/share/doc/hanIM

	# patch XLC_LOCALE for ko_KR.EUC(harmless)
	if [ -f ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE ]; then \
		${MV} -f ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE \
			 ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE.orig; \
	fi
	${INSTALL_DATA} ${FILESDIR}/XLC_LOCALE \
		${PREFIX}/lib/X11/locale/ko/
	${INSTALL_DATA} ${FILESDIR}/XLC_LOCALE \
		${PREFIX}/share/doc/hanIM/

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
