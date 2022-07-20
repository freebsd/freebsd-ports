PORTNAME=	covtool
PORTVERSION=	2.1
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/rel_2.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ test coverage analyzer

USES=		gmake zip
USE_GCC=	yes

MAKEFILE=	makefile
MAKE_ARGS=	CC=${CXX} LN=${CXX} INSTALL_DIR=${STAGEDIR}${PREFIX}
NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%PORTNAME%%|${PORTNAME}|g' ${WRKSRC}/cov++
	@${REINPLACE_CMD} 's|%%CXXFLAGS%%|${CXXFLAGS}|g' \
		${WRKSRC}/rules.FreeBSD

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/*.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/cov++.cfg ${STAGEDIR}${PREFIX}/etc/cov++.cfg.sample

.include <bsd.port.mk>
