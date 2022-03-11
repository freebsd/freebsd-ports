PORTNAME=	stress-ng
DISTVERSIONPREFIX=	V
DISTVERSION=	0.13.12
PORTREVISION=	0
CATEGORIES=	benchmarks

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Stress test benchmarks

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	ColinIanKing

ALL_TARGET=	# empty

PLIST_FILES=	bin/stress-ng man/man1/stress-ng.1.gz

OPTIONS_DEFINE=		JUDY LIBINOTIFY
OPTIONS_DEFINE_amd64=	INTELIPSEC
OPTIONS_DEFAULT=	JUDY LIBINOTIFY
OPTIONS_DEFAULT_amd64=	INTELIPSEC

INTELIPSEC_DESC=	Enable support for Intel's IPsec library
JUDY_DESC=		Enable support for (lib)Judy
LIBINOTIFY_DESC=	Enable support for libinotify

INTELIPSEC_LIB_DEPENDS=		libIPSec_MB.so:security/intel-ipsec-mb
INTELIPSEC_MAKE_ARGS_OFF=	HAVE_LIB_IPSEC_MB=0

JUDY_LIB_DEPENDS=		libJudy.so:devel/judy
JUDY_MAKE_ARGS_OFF=		HAVE_LIB_JUDY=0

LIBINOTIFY_LIB_DEPENDS=		libinotify.so:devel/libinotify
LIBINOTIFY_LDFLAGS=		-linotify
LIBINOTIFY_MAKE_ARGS_OFF=	HAVE_SYS_INOTIFY_H=0

MAKE_ARGS=	VERBOSE=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stress-ng ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/stress-ng.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
