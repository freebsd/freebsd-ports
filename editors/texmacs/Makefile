# New ports collection makefile for:	texmacs
# Date created:		1 December 2001
# Whom:			Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	texmacs
PORTVERSION=	1.0.1.21
CATEGORIES=	editors print
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/
DISTNAME=	TeXmacs-${PORTVERSION}-src

MAINTAINER=	mainland@apeiron.net
COMMENT=	"A free WYSIWYG scientific text editor."

BROKEN=		"Does not fetch"

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile \
		tex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}/TeXmacs-${PORTVERSION}-src

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-fastalloc ${CONFIGURE_TARGET}
USE_GMAKE=	yes

ALL_TARGET=

MAN1=		texmacs.1 fig2ps.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
