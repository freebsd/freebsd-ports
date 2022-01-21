PORTNAME=	dobutsu
DISTVERSION=	3
CATEGORIES=	games
MASTER_SITES=	http://fuz.su/~fuz/dobutsu/

MAINTAINER=	fuz@fuz.su
COMMENT=	Tablebase and Engine for Dobutsu Shogi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-runtime gettext-tools localbase:ldflags pkgconfig readline tar:xz

MAKE_ARGS=	CC="${CC}" \
		LDFLAGS="${LDFLAGS}" \
		NPROC="${MAKE_JOBS_NUMBER}" \
		PREFIX="${PREFIX}" \
		RLCFLAGS= \
		STAGING=${STAGEDIR}
CFLAGS=		-DNDEBUG

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/dobutsu

.include <bsd.port.mk>
