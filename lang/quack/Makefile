# New ports collection makefile for:	Quack
# Date created:				24 October 2003
# Whom:					Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	quack
PORTVERSION=	0.27
CATEGORIES=	lang scheme elisp
MASTER_SITES=	http://www.neilvandyke.org/quack/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.el
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced support for editing and running Scheme code

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

EMACS_PORT_NAME?=	emacs21

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/quack/quack.el \
		${EMACS_VERSION_SITE_LISPDIR}/quack/quack.elc
PLIST_DIRS=	${EMACS_VERSION_SITE_LISPDIR}/quack

ELISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"does not build on ia64"
.endif

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -q -f batch-byte-compile quack.el

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/quack.* ${ELISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
