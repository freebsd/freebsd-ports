# Created by: Matthieu BOUTHORS
# $FreeBSD$

PORTNAME=	pgtune
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2449/ \
		https://www.glenbarber.us/ports/${CATEGORIES}/${PORTNAME}/

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	Postgresql.conf tuning tips based on hardware and load type

USES=		shebangfix
USE_PYTHON=	2+
NO_BUILD=	yes

SHEBANG_FILES=	${PORTNAME}
python_OLD_CMD=	${PREFIX}/bin/python

pre-install:
	@${REINPLACE_CMD} -e 's|${python_OLD_CMD}|${PYTHON_CMD}|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgtune  ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pgtune/settings
	${INSTALL_DATA} ${WRKSRC}/pg_settings* \
		${STAGEDIR}${PREFIX}/share/pgtune/settings

.include <bsd.port.mk>
