PORTNAME=	tkmoo
PORTVERSION=	0.3.32
PORTREVISION=	3
CATEGORIES=	games tk
MASTER_SITES=	http://www.awns.com/tkMOO-light/Source/
DISTNAME=	tkMOO-light-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk-based M** client with scripting support

LICENSE=	TKMOO # non-commercial
LICENSE_NAME=	tkMOO license
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		tk:run
MAKE_ENV+=	TKMOO_LIB_DIR="${DATADIR}" \
		TKMOO_BIN_DIR="${PREFIX}/bin" WISH8.3="${WISH}"

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/* ${STAGEDIR}${DATADIR}/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/tkMOO-lite ${STAGEDIR}${PREFIX}/bin/tkmoo

.include <bsd.port.mk>
