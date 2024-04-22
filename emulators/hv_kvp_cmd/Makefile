PORTNAME=	hv_kvp_cmd
DISTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Hyper-V Data Exchange Service (KVP), users command line utility
WWW=		https://github.com/pol73/hv_kvp_cmd/

LICENSE=	MIT

.if !exists(${SRC_BASE}/sys/dev/hyperv/utilities/hv_kvp.h)
IGNORE=	requires system source tree in the ${SRC_BASE}
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	pol73

MAKE_ARGS+=	LOCAL=${STAGEDIR}${PREFIX} MANDIR=share/man

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
