PORTNAME=	freebsd-ftpd
DISTVERSIONPREFIX=	v
DISTVERSION=	20260507a
PORTREVISION=	1
CATEGORIES=	ftp

MAINTAINER=	cy@FreeBSD.org
COMMENT=	FreeBSD ftpd
WWW=		https://github.com/cschuber/freebsd-ftpd

LICENSE=	BSD3CLAUSE

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	cschuber

USE_RC_SUBR=	ftpd

MAKE_ARGS+=		BINOWN=${BINOWN} BINMODE=${BINMODE}
MAKE_ENV+=		MAKESYSPATH=/usr/src/share/mk \
			BINDIR=${PREFIX}/libexec \
			MANDIR=${PREFIX}/share/man/man \
			MK_WERROR=no

OPTIONS_DEFINE=		IPV6 LIBBLOCKLIST
OPTIONS_DEFAULT=	IPV6 LIBBLOCKLIST

LIBBLOCKLIST_DESC=	libblocklist(3) support for rlogind(8) and rshd(8)
LIBBLOCKLIST_MAKE_ARGS=	USE_LIBBLOCKLIST=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBBLOCKLIST}
. if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500000
LIBBLOCKLIST_MAKE_ARGS=	USE_LIBBLACKLIST=yes
EXTRA_PATCHES=		${FILESDIR}/libblacklist-patches
. endif
.endif

.include <bsd.port.mk>
