# New ports collection makefile for:	texmacs
# Date created:		1 December 2001
# Whom:			Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	texmacs
PORTVERSION=	1.0.4.3
CATEGORIES=	editors print
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/ \
		ftp://ftp.texmacs.org/pub/TeXmacs/old-targz/
DISTNAME=	TeXmacs-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"A free WYSIWYG scientific text editor."

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile \
		tex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-fastalloc ${CONFIGURE_TARGET}
USE_GMAKE=	yes

ALL_TARGET=

MAN1=		texmacs.1 fig2ps.1
MANCOMPRESSED=	yes

pre-install:
	cd ${WRKSRC} ; find . -name '*.orig' -delete

.include <bsd.port.mk>
