# New ports collection makefile for:	texmacs
# Date created:		1 December 2001
# Whom:			Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	texmacs
PORTVERSION=	1.0
CATEGORIES=	editors print
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/
DISTFILES=	TeXmacs-${PORTVERSION}-src.tar.gz \
		TeXmacs-600dpi-fonts.tar.gz

MAINTAINER=	mainland@apeiron.net

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile \
		tex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX

WRKSRC=	${WRKDIR}/TeXmacs-${PORTVERSION}-src

USE_XLIB=	yes
GNU_CONFIGURE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

ALL_TARGET=

MAN1=		texmacs.1 fig2ps.1
MANCOMPRESSED=	yes

post-extract:
	@(cd ${WRKSRC}/TeXmacs-${PORTVERSION}; \
		${TAR} xzf ${DISTDIR}/TeXmacs-600dpi-fonts.tar.gz)

.include <bsd.port.mk>
