# New ports collection makefile for:	enfle
# Date created:		Tue Sep 28 02:25:17 JST 1999
# Whom:			Yuki Sawada <samy@goldmoon.org>
#
# $FreeBSD$
#

PORTNAME=	enfle
PORTVERSION=	20010130
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://enfle.fennel.org/files/stable/

MAINTAINER=	samy@goldmoon.org
COMMENT=	Simple plugin-based graphics viewer

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		mng.1:${PORTSDIR}/graphics/libmng \
		ungif.5:${PORTSDIR}/graphics/libungif \
		arc.1:${PORTSDIR}/archivers/libarc
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_INC_LIBTOOL_VER=13
USE_PERL5_BUILD=yes
CONFIGURE_ARGS=	--enable-all-plugins \
		--enable-plugins-dir \
		--enable-loader=ungif \
		--disable-static

MAN1=		enfle.1

.include <bsd.port.pre.mk>

post-patch:
	${PERL} -pi -e 's/^(.*_la_LDFLAGS = -module)$$/\1 -avoid-version/' \
		${WRKSRC}/plugins/*/*/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/enfle.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
