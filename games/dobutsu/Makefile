PORTNAME=	dobutsu
DISTVERSION=	6
CATEGORIES=	games
MASTER_SITES=	http://fuz.su/pub/dobutsu/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Tablebase and Engine for Dobutsu Shogi
WWW=		https://github.com/clausecker/dobutsu

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-runtime gettext-tools localbase:ldflags pkgconfig readline tar:xz

MAKE_ARGS=	CC="${CC}" \
		LDFLAGS="${LDFLAGS}" \
		NPROC="${MAKE_JOBS_NUMBER}" \
		PREFIX="${PREFIX}" \
		RLCFLAGS= \
		STAGING=${STAGEDIR}
CFLAGS+=	${WITH_DEBUG:D:U-DNDEBUG}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/dobutsu

do-test:
	${WRKSRC}/validatetb ${WRKSRC}/dobutsu.tb.xz

.include <bsd.port.mk>
