# New ports collection makefile for:	Migemo
# Date created:		19 February 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	migemo
PORTVERSION=	0.21
CATEGORIES=	japanese elisp
MASTER_SITES=   http://migemo.namazu.org/stable/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	nobutaka@nobutaka.com

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME} \
		${NONEXISTENT}:${SKK_PORT_DIR}:extract
RUN_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}

USE_PERL5=	yes
USE_AUTOCONF=	yes

EMACS_PORT_NAME=emacs20
SKK_PORT_DIR=	${PORTSDIR}/japanese/skk-jisyo

.include <bsd.port.pre.mk>

SKK_WRKSRC!=	cd ${SKK_PORT_DIR}; ${MAKE} -V WRKSRC

post-extract:
	${MKDIR} ${WRKSRC}/Lingua
	${CP} ${WRKSRC}/Lingua-Romkan/Romkan.pm ${WRKSRC}/Lingua
	${CP} ${SKK_WRKSRC}/jisyo/SKK-JISYO.L ${WRKSRC}

post-build:
	(cd ${WRKSRC}/Lingua-Romkan/; ${PERL} Makefile.PL; ${MAKE})

pre-install:
	(cd ${WRKSRC}/Lingua-Romkan/; ${MAKE} install)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
