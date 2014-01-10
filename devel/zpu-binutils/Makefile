# $FreeBSD$

PORTNAME=	zpu-binutils
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	zpu-toolchain-${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	ZPU toolchain

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${DISTNAME}/toolchain
MANDIRS=	${PREFIX}/zpu/man

USES=		gettext gmake

INFO=		zpu/as zpu/bfd zpu/binutils zpu/configure zpu/ld zpu/standards

post-patch:
	@${REINPLACE_CMD} -e 's/%%CC%%/${CC}/' ${WRKSRC}/build.sh
	@${CP}  ${FILESDIR}/install.sh ${WRKSRC}
	@${REINPLACE_CMD} -e 's|%%GMAKE%%|${GMAKE}|g' ${WRKSRC}/build.sh \
		${WRKSRC}/install.sh
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/build.sh
	@${REINPLACE_CMD} -e 's|%%DESTDIR%%|${STAGEDIR}|g' ${WRKSRC}/binutils/Makefile.in

do-install:
	@cd ${WRKSRC} && ${SH} install.sh

do-build:
	@cd ${WRKSRC} && ${SH} build.sh

.include <bsd.port.mk>
