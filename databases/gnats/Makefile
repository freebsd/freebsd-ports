# New ports collection makefile for:	gnats
# Version required:     3.97-beta
# Date created:		10 November 1995
# Whom:			pst
#
# $Id: Makefile,v 1.7 1996/11/17 03:18:23 obrien Exp $
#

DISTNAME=       gnats-3.97-beta
CATEGORIES=	databases
MASTER_SITES=   ftp://ftp.cygnus.com/pub/

MAINTAINER=	pst@FreeBSD.org

# we've got some .elc and info files to compile (yuck)
BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs \
		gm4:${PORTSDIR}/devel/m4

NO_PACKAGE=	"Requires gnats UID"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX} \
		--with-lispdir=${PREFIX}/share/emacs/site-lisp \
		--with-full-gnats
USE_GMAKE=	yes
MAN1=		edit-pr.1 gnats.1 query-pr.1 send-pr.1
MAN8=		mkcat.8 rmcat.8 mkdist.8 query-pr.8 file-pr.8 gen-index.8

# this stops the configuration program from pulling installation
# information in from the standard freebsd send-pr program
CONFIGURE_ENV=  SEND_PR=/usr/bin/false

# the gnats distribution comes with a lot of baggage we don't want to install
# just install gnats
INSTALL_TARGET=	install-gnats install-send-pr

post-build:
	(cd ${WRKSRC}/gnats;   ${MAKE} info)
	(cd ${WRKSRC}/send-pr; ${MAKE} info)

post-install:
	(cd ${WRKSRC}/gnats;   ${MAKE} install-info)
	(cd ${WRKSRC}/send-pr; ${MAKE} install-info)

.include <bsd.port.mk>
