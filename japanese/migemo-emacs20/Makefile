# New ports collection makefile for:	Migemo
# Date created:		19 February 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	migemo
PORTVERSION=	0.21
PORTREVISION=	1
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
BUILD_DEPENDS+=	${NONEXISTENT}:${SKK_PORT_DIR}:extract

USE_PERL5=	yes
USE_AUTOMAKE=	yes

CONFIGURE_ARGS=		--with-emacs=${EMACS_CMD}
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
CONFIGURE_ARGS+=	--with-lispdir=${PREFIX}/${EMACS_LIBDIR}/site-lisp
.endif

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
