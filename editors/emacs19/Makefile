# New ports collection makefile for:	GNU emacs
# Date created:		29 October 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	emacs
PORTVERSION=	19.34b
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU editing macros

CONFLICTS=	emacs-21.* emacs-20.* \
		xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]*

ONLY_FOR_ARCHS=	i386
DEPRECATED=	"editors/emacs is recommended instead for new installations"

EMACS_VERSION=	19.34
CONFIGURE_TARGET=	${MACHINE_ARCH}--freebsd
PLIST_SUB=	EMACS_VERSION=${EMACS_VERSION} EMACS_ARCH=${CONFIGURE_TARGET}
NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/emacs-19.34
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
.if !defined(WITHOUT_X11)
CONFIGURE_ARGS=	--with-x-toolkit --sharedstatedir=/var/run
USE_XLIB=	yes
.else
CONFIGURE_ARGS=	--with-x=no --sharedstatedir=/var/run
.endif

STRIP=
MAN1=		emacs.1 etags.1 ctags.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
BROKEN=		"invalid packing list"
.endif

post-install:
.for file in emacs-19.34 emacsclient etags ctags b2m
	${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
.for info in emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
# install emacs.sh into ${PREFIX}/etc/rc.d
	${CHMOD} 1777 /var/run/emacs/lock
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${FILESDIR}/emacs.sh ${PREFIX}/etc/rc.d

.include <bsd.port.post.mk>
