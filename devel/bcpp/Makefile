PORTNAME=	bcpp
DISTVERSION=	20250914
CATEGORIES=	devel
MASTER_SITES=	https://invisible-mirror.net/archives/${PORTNAME}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Utility similar to indent for C++ code
WWW=		https://invisible-island.net/bcpp/bcpp.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

CFLAGS+=	-DBCPP_CONFIG_DIR=\\\"${PREFIX}/etc/${PORTNAME}\\\"

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/code/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/code/${PORTNAME}.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/txtdocs/hirachy.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/txtdocs/manual.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
