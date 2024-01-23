PORTNAME=	libsysinfo
PORTVERSION=	0.0.3
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	imp@bsdimp.com
COMMENT=	GNU libc's sysinfo port for FreeBSD
WWW=		https://github.com/bsdimp/libsysinfo

LICENSE=	BSD3CLAUSE

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp

USE_LDCONFIG=	yes

LDFLAGS+=	-lkvm

PLIST_FILES=	include/sys/sysinfo.h \
		lib/libsysinfo.a \
		lib/libsysinfo.so \
		lib/libsysinfo.so.0 \
		libdata/pkgconfig/libsysinfo.pc \
		share/man/man3/sysinfo.3.gz

SUB_FILES=	libsysinfo.pc
SUB_LIST=	PREFIX="${PREFIX}" PORTVERSION="${PORTVERSION}" COMMENT="${COMMENT}"

post-patch:
	@${REINPLACE_CMD} -e 's|man/man|share/man/man|g' \
		${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKDIR}/libsysinfo.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
