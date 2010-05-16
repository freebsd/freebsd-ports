# New ports collection makefile for:	CHICKEN
# Date created:				31 December 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	chicken
PORTVERSION=	4.5.0
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.call-with-current-continuation.org/ \
		http://chicken.wiki.br/releases/${PORTVERSION}/

MAINTAINER=	vmagerya@gmail.com
COMMENT=	A Scheme-to-C compiler

USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS+=	PLATFORM=bsd PREFIX=${PREFIX} \
		TOPMANDIR=${PREFIX}/man ARCH=${NEW_ARCH}

PLATFORM=	bsd
NEW_ARCH=	${ARCH:S/i386/x86/:S/amd64/x86-64/}

MAN1=		chicken.1 chicken-bug.1 chicken-install.1 chicken-profile.1 \
		chicken-status.1 chicken-uninstall.1 csc.1 csi.1

.include <bsd.port.pre.mk>

.if ${ARCH} != "amd64" && ${ARCH} != "i386" && ${ARCH} != "sparc64"
MAKE_ARGS+=	HACKED_APPLY=
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
