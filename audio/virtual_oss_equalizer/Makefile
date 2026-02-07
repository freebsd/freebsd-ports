PORTNAME=	virtual_oss_equalizer
PORTVERSION=	${OSVERSION}
CATEGORIES=	audio
DISTFILES=

MAINTAINER=	christos@FreeBSD.org
COMMENT=	virtual_oss equalizer utility
WWW=		https://freebsd.org

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		pathfix uidfix

MAKE_ENV=	BINDIR=${PREFIX}/sbin \
		MANDIR=${PREFIX}/share/man/man \
		MAKEOBJDIRPREFIX=${WRKDIR}

WRKSRC=		${SRC_BASE}/usr.sbin/virtual_oss/virtual_equalizer

PLIST_FILES=	sbin/virtual_equalizer \
		share/man/man8/virtual_equalizer.8.gz

.include <bsd.port.pre.mk>

.if !exists(${WRKSRC})
IGNORE=		requires FreeBSD source files in ${SRC_BASE}
.endif

.include <bsd.port.post.mk>
