PORTNAME=	freebsd-ftpd
DISTVERSIONPREFIX=	v
DISTVERSION=	20220711
PORTREVISION=	2
CATEGORIES=	ftp

MAINTAINER=	cy@FreeBSD.org
COMMENT=	FreeBSD ftpd

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	cschuber

USES=		uidfix

MAKE_ARGS+=		BINOWN=${BINOWN} BINMODE=${BINMODE}
MAKE_ENV+=		MAKESYSPATH=/usr/src/share/mk \
			BINDIR=${PREFIX}/libexec \
			MANDIR=${PREFIX}/man/man

OPTIONS_DEFINE=		IPV6 LIBBLACKLIST
OPTIONS_DEFAULT=	IPV6 LIBBLACKLIST
.if !exists(/usr/include/blacklist.h)
OPTIONS_EXCLUDE=	LIBBLACKLIST
.endif

LIBBLACKLIST_DESC=	libblacklist(3) support for rlogind(8) and rshd(8)
LIBBLACKLIST_MAKE_ARGS=	USE_LIBBLACKLIST=yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1300134
MAKE_ENV+=	MK_WERROR=no
.else
MAKE_ENV+=	NO_WERROR=1
.endif

.include <bsd.port.mk>
