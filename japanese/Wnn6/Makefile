# New ports collection makefile for:	Wnn6-demo
# Version required:	97.6.6
# Date created:		15 July 1997
# Whom:			Satoshi Taoka <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id: Makefile,v 1.17 1997/09/10 06:51:52 asami Exp $
#

DISTNAME=	OMRONWnn6
PKGNAME=	jp-Wnn6-97.6.6
CATEGORIES=	japanese
EXTRACT_SUFX=	.tgz

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

IGNOREFILES=	${DISTFILES}
WRKSRC=		${WRKDIR}
LIBDIR=		${PREFIX}/OMRONWnn6
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/wnn6.sh
DISTDIR=	${MOUNT_PT}/fbsd
MOUNT_PT?=	/cdrom
MOUNT_DEV?=	/dev/wcd0c

RESTRICTED=	"Restrictive copyright"

NO_CDROM=	yes
NO_PACKAGE=	yes
NO_CONFIGURE=	yes
NO_PATCH=	yes
IS_INTERACTIVE=	yes

do-fetch:
	@echo -n "Please set the CD-ROM of 'Wnn6' into your cdrom-drive. (Press Return)"; \
	read dummy; \
	echo "A mount point and the device file are '${MOUNT_PT}' and '${MOUNT_DEV}' respectively."; \
	echo -n "Are these correct? (y/n) [y]"; \
	(read ans; \
	case x$${ans} in \
	  xn*|xN*) \
		echo "Please rerun 'make' in specifying MOUNT_PT and MOUNT_DEV"; \
		echo "For example:"; \
		echo "	make MOUNT_PT=/mnt MOUNT_DEV=/dev/cd0c"; \
		/usr/bin/false; \
		;; \
	  *) \
		echo "Now mounting the CD-ROM ..."; \
		;; \
	esac)
	@for t in `mount | grep ${MOUNT_PT}`; do \
	  if [ x"$$t" = x"${MOUNT_PT}" ]; then \
	    echo "##################################################"; \
	    echo "${MOUNT_PT} is busy"; \
	    echo "Please umount ${MOUNT_PT}"; \
	    echo "##################################################"; \
	    /usr/bin/false; \
	  fi; \
	done
	@/sbin/mount_cd9660 ${MOUNT_DEV} ${MOUNT_PT}

pre-extract:
	@if [ ! -e ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		echo "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}: No such file"; \
		echo "Perhaps the CD-ROM is not one of Wnn6"; \
		/sbin/umount ${MOUNT_PT}; \
		echo "Umounting is done ..."; \
		/usr/bin/false; \
	fi

do-build:
	@/sbin/umount ${MOUNT_PT}

do-install:
	@cd ${WRKSRC}/usr; tar cf - OMRONWnn6 | (cd ${PREFIX}; tar xvpf -)
	@${INSTALL_SCRIPT} ${FILESDIR}/setup.sh ${LIBDIR}
	@if [ ! -f ${STARTUP_SCRIPT} ]; then 				\
		echo "Installing ${STARTUP_SCRIPT} startup file."; 	\
		echo '#!/bin/sh' > ${STARTUP_SCRIPT}; 			\
		echo 'wnn6=/usr/local/bin/Wnn6/jserver' 		\
		  >> ${STARTUP_SCRIPT} ;				\
		echo 'if [ -f $$wnn6 ]; then' >> ${STARTUP_SCRIPT} ;	\
		echo "    echo -n ' Wnn6'" >> ${STARTUP_SCRIPT};	\
		echo '     $$wnn6' >> ${STARTUP_SCRIPT} ;		\
		echo "fi" >> ${STARTUP_SCRIPT} ;			\
		chmod 755 ${STARTUP_SCRIPT} ;				\
		chown bin.bin ${STARTUP_SCRIPT};			\
	fi

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
