PORTNAME=	jtans
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_appli-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ancient puzzle
WWW=		https://jtans.sourceforge.net/

LICENSE=	GPLv2+ # got from website

USES=		java

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_BUILD=	yes
SUB_FILES=	jtans.sh
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jtans.sh ${STAGEDIR}${PREFIX}/bin/jtans
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jtans_appli-1.0.jar ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
