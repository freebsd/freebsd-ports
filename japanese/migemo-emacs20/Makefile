# New ports collection makefile for:	Migemo
# Date created:		19 February 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	migemo
PORTVERSION=	0.3
PORTEPOCH=	1
CATEGORIES=	japanese elisp
MASTER_SITES=   http://migemo.namazu.org/stable/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	nobutaka@nobutaka.com

EMACS_PORT_NAME?=	emacs20

.if (${EMACS_PORT_NAME} == "xemacs21-mule")
EMACS_PACKAGESDIR=	lib/xemacs/site-packages

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp/apel/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp/apel/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
.else
BUILD_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
.endif

USE_AUTOMAKE=	yes
USE_RUBY=	yes
BUILD_DEPENDS+=	${RUBY_SITELIBDIR}/romkan.rb:${PORTSDIR}/japanese/ruby-romkan \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/romkan.rb:${PORTSDIR}/japanese/ruby-romkan \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch

CONFIGURE_ARGS=		--with-rubydir=${RUBY_SITELIBDIR} --with-emacs=${EMACS_CMD}
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
CONFIGURE_ARGS+=	--with-lispdir=${PREFIX}/${EMACS_LIBDIR}/site-lisp
.endif

.include <bsd.port.pre.mk>

post-configure:
	${RUBY} -i -pe 'sub /@list=/, "list="' ${WRKSRC}/${MAKEFILE}

post-install:
	@${MKDIR} ${PREFIX}/share/doc/migemo
	@${MV} ${PREFIX}/share/migemo/migemo.ja.html ${PREFIX}/share/doc/migemo
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
