# New ports collection makefile for:	prime-el (for emacsen)
# Date created:				16 Jun 2003
# Whom:					Gen Otsuji<otsuji@users.sourceforge.jp>
#
# $FreeBSD$
#

PORTNAME=	prime
PORTVERSION=	1.5.1.3
CATEGORIES=	japanese
MASTER_SITES=	http://prime.sourceforge.jp/src/
PKGNAMESUFFIX=	-el
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	otsuji@users.sourceforge.jp
COMMENT=	Emacs lisp set for the prime

RUN_DEPENDS+=	${LOCALBASE}/share/emacs/site-lisp/init-mell.el:${PORTSDIR}/japanese/mell \
		${LOCALBASE}/share/emacs/site-lisp/init-suikyo.el:${PORTSDIR}/japanese/suikyo \
		prime:${PORTSDIR}/japanese/prime

GNU_CONFIGURE=	yes
USE_AUTOMAKE_VER=	19
USE_AUTOCONF_VER=	259

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL})

post-install:
	cd ${WRKSRC}; ${MAKE} install-etc
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc; ${MAKE} ${INSTALL_TARGET}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
