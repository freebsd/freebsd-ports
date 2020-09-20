# Created by: M. Warner Losh <imp@freebsd.org>
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=	7.10
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GNU
PKGNAMEPREFIX=	arm-none-eabi-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU GDB for the arm bare metal target

LICENSE=	GPLv3

DEPRECATED=	This is an old, obsolete version of gdb
EXPIRATION_DATE=2020-12-31

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		gmake tar:xz iconv gmake libtool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=arm-none-eabi --program-prefix=arm-none-eabi- --disable-nls \
		--disable-werror --with-python=no

pre-configure:
	cd ${WRKSRC} ; ${RM} -r dejagnu expect tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.mk>
