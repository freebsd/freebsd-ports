# Created by: Gen Otsuji<otsuji@users.sourceforge.jp>
# $FreeBSD$

PORTNAME=	prime
DISTVERSION=	1.0.0.1
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES=	http://prime.sourceforge.jp/src/

MAINTAINER=	otsuji@users.sourceforge.jp
COMMENT=	PRedictive Input Method Editor(PRIME)

LIB_DEPENDS=	sary.10:${PORTSDIR}/textproc/sary
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/sary.so:${PORTSDIR}/textproc/ruby-sary \
		${LOCALBASE}/share/emacs/site-lisp/init-suikyo.el:${PORTSDIR}/japanese/suikyo \
		${LOCALBASE}/share/prime/dict/prime-dict:${PORTSDIR}/japanese/prime-dict

USE_RUBY=		yes
USE_RUBY_FEATURES=	iconv
RUBY_WITH_PTHREAD=	yes

USES=			pkgconfig
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-rubydir=${RUBY_SITELIBDIR}
USE_AUTOTOOLS=	automake autoconf
MAKE_JOBS_UNSAFE=	yes

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL})

post-install:
	cd ${WRKSRC}; ${MAKE} install-etc
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc; ${MAKE} ${INSTALL_TARGET}
.endif

.include <bsd.port.mk>
