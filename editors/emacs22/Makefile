# New ports collection makefile for:	GNU emacs
# Version required:	19.34b
# Date created:		29 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.35 1999/01/23 14:28:19 simokawa Exp $
#

DISTNAME=	emacs-19.34b
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs

MAINTAINER=	ports@FreeBSD.ORG

EMACS_VERSION=	19.34
EMACS_ARCH=	${MACHINE_ARCH}--freebsd
PLIST_SUB=	EMACS_VERSION=${EMACS_VERSION} EMACS_ARCH=${EMACS_ARCH}
NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/emacs-19.34
GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	${EMACS_ARCH} --with-x-toolkit --sharedstatedir=/var/run

STRIP=
MAN1=		emacs.1 etags.1 ctags.1

post-install:
.for file in emacs-19.34 emacsclient etags ctags b2m
	strip ${PREFIX}/bin/${file}
.endfor
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
# install emacs.sh into ${PREFIX}/etc/rc.d
	chmod 1777 /var/run/emacs/lock
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${FILESDIR}/emacs.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
