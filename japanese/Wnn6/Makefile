# New ports collection makefile for:	Wnn6
# Version required:	97.6.6
# Date created:		15 July 1997
# Whom:			Satoshi Taoka <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id: Makefile,v 1.20 1998/06/27 05:19:00 asami Exp $
#

DISTNAME=	OMRONWnn6
PKGNAME=	ja-Wnn6-97.6.6
CATEGORIES=	japanese
EXTRACT_SUFX=	.tgz

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

IGNOREFILES=	${DISTFILES}
WRKSRC=		${WRKDIR}
LIBDIR=		${PREFIX}/OMRONWnn6
DISTDIR=	${MOUNT_PT}/fbsd
MOUNT_PT?=	/cdrom
MOUNT_DEV?=	/dev/wcd0c

RESTRICTED=	"You should buy from Omron Software Co., Ltd."
NO_CDROM=	"You should buy from Omron Software Co., Ltd."
NO_PACKAGE=	"You should buy from Omron Software Co., Ltd."
NO_BUILD=	yes
IS_INTERACTIVE=	yes

do-fetch:
	@${DO_NADA}

# If ${.CURDIR}/work/.build_done (which will be ${BUILD_COOKIE}) exists,
# we do nothing in a 'do-fetch' stage.
.if !exists(${.CURDIR}/work/.build_done)
pre-extract:
	@${ECHO} -n "Please set the CD-ROM of 'Wnn6' into your cdrom-drive. (Press Return)"; \
	read dummy; \
	${ECHO} "By default, a mount point and a device file"; \
	${ECHO} "    are '${MOUNT_PT}' and '${MOUNT_DEV}' respectively."; \
	${ECHO} -n "Are these correct? (y/n) [y]"; \
	(read ans; \
	case x$${ans} in \
	  xn*|xN*) \
		${ECHO} "###########################################################"; \
		${ECHO} "Please rerun 'make' in specifying MOUNT_PT and MOUNT_DEV"; \
		${ECHO} "For example:"; \
		${ECHO} "	make MOUNT_PT=/mnt MOUNT_DEV=/dev/cd0c"; \
		${ECHO} "###########################################################"; \
		/usr/bin/false; \
		;; \
	  *) \
		${ECHO} "Now mounting the CD-ROM ..."; \
		;; \
	esac)
	@for t in `mount | ${GREP} ${MOUNT_PT}`; do \
	  if [ x"$$t" = x"${MOUNT_PT}" ]; then \
	    ${ECHO} "##################################################"; \
	    ${ECHO} "${MOUNT_PT} is busy"; \
	    ${ECHO} "Please 'umount ${MOUNT_PT}'"; \
	    ${ECHO} "##################################################"; \
	    /usr/bin/false; \
	  fi; \
	done
	@/sbin/mount_cd9660 ${MOUNT_DEV} ${MOUNT_PT}
.endif

pre-extract:
	@if [ ! -e ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO} "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}: No such file"; \
		${ECHO} "Perhaps the CD-ROM is not one of Wnn6"; \
		/sbin/umount ${MOUNT_PT}; \
		${ECHO} "Umounting is done ..."; \
		/usr/bin/false; \
	fi

post-extract:
	@/sbin/umount ${MOUNT_PT}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

do-install:
	@cd ${WRKSRC}/usr; tar cf - OMRONWnn6 | (cd ${PREFIX}; tar xvpf -)

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
