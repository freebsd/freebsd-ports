# Created by: Matthieu BOUTHORS
# $FreeBSD$

PORTNAME=	pgtune
PORTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2449/ \
		https://www.glenbarber.us/ports/${CATEGORIES}/${PORTNAME}/

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	Postgresql.conf tuning tips based on hardware and load type

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgtune ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pgtune/settings
	${INSTALL_DATA} ${WRKSRC}/pg_settings* \
		${STAGEDIR}${PREFIX}/share/pgtune/settings

.include <bsd.port.mk>
