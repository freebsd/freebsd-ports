PORTNAME=	zpaqfranz
DISTVERSION=	55.12
CATEGORIES=	archivers
MASTER_SITES=	http://www.francocorbelli.it/zpaqfranz/freebsd/

MAINTAINER=	franco@francocorbelli.com
COMMENT=	Swiss army knife for the serious backup manager

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	dual

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/dir \
		bin/zpaqfranz

.include <bsd.port.pre.mk>

.if ${ARCH} != "amd64"
CFLAGS+=	-DNOJIT
.endif

.include <bsd.port.post.mk>
