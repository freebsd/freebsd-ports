# New ports collection makefile for:	ja-prime
# Date created:				6 Jun 2003
# Whom:					Gen Otsuji<otsuji@users.sourceforge.jp>
#
# $FreeBSD$
#

PORTNAME=	prime
DISTVERSION=	1.0.0.1
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES=	http://prime.sourceforge.jp/src/

MAINTAINER=	otsuji@users.sourceforge.jp
COMMENT=	PRedictive Input Method Editor(PRIME)

LIB_DEPENDS=	sary.10:${PORTSDIR}/textproc/sary
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/sary.so:${PORTSDIR}/textproc/ruby-sary \
		${RUBY_ARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv \
		${LOCALBASE}/share/emacs/site-lisp/init-suikyo.el:${PORTSDIR}/japanese/suikyo \
		${LOCALBASE}/share/prime/dict/prime-dict:${PORTSDIR}/japanese/prime-dict

USE_RUBY=		yes
RUBY_WITH_PTHREAD=	yes

USE_GNOME=		pkgconfig
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-rubydir=${RUBY_SITELIBDIR}
USE_AUTOTOOLS=	automake:111 autoconf:268
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=		LOCALBASE=${LOCALBASE}

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL})

post-install:
	cd ${WRKSRC}; ${MAKE} install-etc
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc; ${MAKE} ${INSTALL_TARGET}
.endif

.include <bsd.port.mk>
