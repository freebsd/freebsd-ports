# Created by: petef
# $FreeBSD$

PORTNAME=	claraocr
PORTVERSION=	20031214
PORTREVISION=	4
CATEGORIES=	graphics accessibility
MASTER_SITES=	GENTOO
MASTER_SITE_SUBDIR=distfiles
DISTNAME=	clara-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optical character recognition (OCR) utility

RUN_DEPENDS=	pnmenlarge:${PORTSDIR}/graphics/netpbm

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
USES=		shebangfix perl5
USE_XORG=	x11
MAKE_ENV=	MKDIR="${MKDIR}"

SHEBANG_FILES=	clara.pl mkdoc.pl selthresh

MAN1=	clara-adv.1 clara-dev.1 clara.1 selthresh.1

NO_STAGE=	yes
post-install:
	${INSTALL_DATA} ${WRKSRC}/selthresh.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
