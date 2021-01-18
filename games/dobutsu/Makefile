# $FreeBSD$

PORTNAME=	dobutsu
DISTVERSION=	2
CATEGORIES=	games
MASTER_SITES=	http://fuz.su/~fuz/dobutsu/

MAINTAINER=	fuz@fuz.su
COMMENT=	Tablebase and Engine for Dobutsu Shogi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libedit localbase:ldflags tar:xz

CFLAGS+=	-DNDEBUG
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		NPROC="${MAKE_JOBS_NUMBER}" \
		PREFIX="${PREFIX}" \
		RLCFLAGS= \
		STAGING=${STAGEDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/dobutsu

.include <bsd.port.mk>
