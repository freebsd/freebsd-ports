# New ports collection makefile for:	Wnn6
# Date created:		15 July 1997
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Wnn6
PORTVERSION=	97.6.6
CATEGORIES=	japanese
DISTNAME=	OMRONWnn6
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese input method (this is not free)

IGNOREFILES=	${DISTFILES}
NO_WRKSUBDIR=	yes
LIBDIR=		${PREFIX}/OMRONWnn6
DISTDIR=	${MOUNT_PT}/fbsd
MOUNT_PT?=	/cdrom
MOUNT_DEV?=	/dev/acd0c

RESTRICTED=	"You should buy from Omron Software Co., Ltd."
NO_CDROM=	"You should buy from Omron Software Co., Ltd."
NO_BUILD=	yes
IS_INTERACTIVE=	yes

do-fetch:
	@${DO_NADA}
fetch-list:
	@${DO_NADA}

# If ${.CURDIR}/work/.build_done (which will be ${BUILD_COOKIE}) exists,
# we do nothing in a 'do-fetch' stage.
.if !exists(${.CURDIR}/work/.build_done)
pre-extract::
	@${ECHO} "Please set the CD-ROM 'Wnn6 for Linux/FreeBSD -- 97.6.6'";
	@${ECHO} "  (it is an early version !!)";
	@${ECHO} -n "into your cdrom-drive. (Press Return)"; \
	read dummy; \
	${ECHO} "By default, a mount point and a device file"; \
	${ECHO} "    are '${MOUNT_PT}' and '${MOUNT_DEV}' respectively."; \
	${ECHO} -n "Are these correct? (y/n) [y]"; \
	(read ans; \
	case x$${ans} in \
	  xn*|xN*) \
		${ECHO} "###########################################################"; \
		${ECHO} "Please run 'make' in specifying MOUNT_PT and MOUNT_DEV"; \
		${ECHO} "For example:"; \
		${ECHO} "	make MOUNT_PT=/mnt MOUNT_DEV=/dev/cd0c"; \
		${ECHO} "###########################################################"; \
		${FALSE}; \
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
	    ${FALSE}; \
	  fi; \
	done
	@/sbin/mount_cd9660 ${MOUNT_DEV} ${MOUNT_PT}
.endif

pre-extract::
	@if [ ! -e ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO} ""; \
		${ECHO} "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}: No such file"; \
		${ECHO} "Perhaps the CD-ROM is not 'Wnn6 for Linux/FreeBSD'"; \
		${ECHO} "!! Note that 'Wnn6 for Linux/FreeBSD' is an old version !!"; \
		/sbin/umount ${MOUNT_PT}; \
		${ECHO} "Umounting is done ..."; \
		${FALSE}; \
	fi

post-extract:
	@/sbin/umount ${MOUNT_PT}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@cd ${WRKSRC}/usr; tar cf - OMRONWnn6 | (cd ${PREFIX}; tar xvpf -)

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
