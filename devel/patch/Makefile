# Created by: ache
# $FreeBSD$

PORTNAME=	patch
PORTVERSION=	2.7.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU DEBIAN_POOL:dp
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}_${PORTVERSION}-6.debian${EXTRACT_SUFX}:dp

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU patch utility

LICENSE=	GPLv3+

EXTRA_PATCHES=	${WRKDIR}/debian/patches/[^0]*.patch \
		${WRKDIR}/debian/patches/0*.patch
PATCH_STRIP=	-p1

TEST_DEPENDS=	bash:shells/bash

USES=		cpe charsetfix gmake tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CPE_VENDOR=	gnu

TEST_TARGET=	check

PLIST_FILES=	bin/gpatch man/man1/gpatch.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/^LOG_COMPILER =/,+1s|$$(SHELL)|bash|' \
		${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
