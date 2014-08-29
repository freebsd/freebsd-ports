# Created by: Joerg Wunsch <joerg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libbfd
PORTVERSION=	2.19.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
DISTNAME=	binutils-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Universal BFD library from GNU binutils

BUILD_DEPENDS=  ${LOCALBASE}/lib/libiberty.a:${PORTSDIR}/devel/gnulibiberty

CONFLICTS=	mingw-binutils-[0-9]* binutils-[0-9]*

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/bfd

USES=		gmake libtool tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-install-libbfd \
		--enable-commonbfdlib \
		--disable-nls \
		--without-pic \
		--enable-targets=all \
		--disable-werror
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
INFO=		bfd

.include <bsd.port.mk>
