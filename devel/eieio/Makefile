# New ports collection makefile for:   eieio
# Date created:                10 December 2001
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	eieio
PORTVERSION=	0.17.b3
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cedet
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=       ${PORTNAME}-${PORTVERSION:S/.b/beta/}

MAINTAINER=	fuyuki@mj.0038.net

EMACS_PORT_NAME?=	emacs21

USE_GMAKE=	yes

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/eieio

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/eieio.info ${PREFIX}/info
	install-info ${PREFIX}/info/eieio.info ${PREFIX}/info/dir

.include <bsd.port.mk>
