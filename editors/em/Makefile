# New ports collection makefile for:	MicroEmacs/PK-TOY
# Date created:         27 Jan 2001
# Whom:                 Tadashi Yumoto
#
# $FreeBSD$
#

PORTNAME=	em
PORTVERSION=	4.0.17
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www3.famille.ne.jp/~ncc1701/em/
DISTNAME=	${PORTNAME}-4.0.16-lt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full screen editor based on MicroEMACS

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" DEFINES=""

pre-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/epath.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/em ${PREFIX}/bin/em
	${INSTALL_DATA} ${WRKSRC}/emacs.hlp ${PREFIX}/etc/emacs.hlp
	${INSTALL_DATA} ${WRKSRC}/emacs.rc ${PREFIX}/etc/dot.emacsrc

.include <bsd.port.mk>
