# New ports collection makefile for:	gnats
# Date created:		10 November 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	gnats
PORTVERSION=	3.113
CATEGORIES=	databases elisp
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/sourceware/gnats/snapshots/ \
		ftp://mirrors.rcn.net/pub/sourceware/gnats/snapshots/ \
		ftp://sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/gnats/snapshots/

MAINTAINER=	pst@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/share/emacs/site-lisp \
		--with-full-gnats \
		--with-release-based

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
MAN1=		edit-pr.1 query-pr.1 send-pr.1
MAN7=		gnats.7
MAN8=		mkcat.8 rmcat.8 mkdist.8 queue-pr.8 file-pr.8 gen-index.8

# this stops the configuration program from pulling installation
# information in from the standard freebsd send-pr program
CONFIGURE_ENV=	SEND_PR=/usr/bin/false

# the gnats distribution comes with a lot of baggage we don't want to install
# just install gnats
INSTALL_TARGET=	install-gnats install-send-pr

.if defined(WANT_FREEFALL_CFG)
EXTRA_PATCHES=	${FILESDIR}/gnats-edit-pr.patch ${FILESDIR}/file-pr.c.patch
.endif

post-build:
	(cd ${WRKSRC}/gnats;   ${MAKE} info)
	(cd ${WRKSRC}/send-pr; ${MAKE} info)

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	(cd ${WRKSRC}/gnats;   ${MAKE} install-info)
	(cd ${WRKSRC}/send-pr; ${MAKE} install-info)
	install-info ${PREFIX}/info/gnats.info   ${PREFIX}/info/dir
	install-info ${PREFIX}/info/send-pr.info ${PREFIX}/info/dir

.include <bsd.port.mk>
