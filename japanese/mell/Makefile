# Created by: Gen Otsuji<otsuji@users.sourceforge.jp>
# $FreeBSD$

PORTNAME=	mell
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://taiyaki.org/elisp/mell/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs Lisp for taiyaki-elisp, especially for the prime

GNU_CONFIGURE=		yes
USE_AUTOTOOLS=	automake autoconf
AUTOMAKE_ARGS=		-af

NO_STAGE=	yes
pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL})

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc; ${MAKE} ${INSTALL_TARGET}
.endif

.include <bsd.port.mk>
