# New ports collection makefile for:   anthy
# Date created:        26 February 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anthy
PORTVERSION=	4300
CATEGORIES=	japanese
MASTER_SITES=	http://downloads.sourceforge.jp/anthy/4873/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another kana-kanji conversion system

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's| install-lispLISP||g' ${WRKSRC}/src-util/Makefile.in

.include <bsd.port.mk>
