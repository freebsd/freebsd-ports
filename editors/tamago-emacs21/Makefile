# New ports collection makefile for:	tamago
# Date created:		6 March 2000
# Whom:			tetsushi NAKAI <nakai@tsl.pe.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	tamago
PORTVERSION=	4.0.6
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.m17n.org/pub/tamago/ \
		ftp://ftp.kddlabs.co.jp/.6/Japan/m17n.org/tamago/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs20
RUN_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs20

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

EMACS_VER=	20.6
PLIST_SUB=	EMACS_VER=${EMACS_VER}

pre-configure:
	@${PERL} -pi -e 's|emacs/site-lisp|emacs/${EMACS_VER}/site-lisp|g' \
	    ${WRKSRC}/configure

.include <bsd.port.mk>
