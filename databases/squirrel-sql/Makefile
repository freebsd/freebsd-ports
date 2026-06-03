PORTNAME=	squirrel-sql
DISTVERSION=	5.1.0
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/1-stable/${DISTVERSION}-plainzip
DISTNAME=	squirrelsql-${DISTVERSION}-optional

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Universal SQL Client
WWW=		http://www.squirrelsql.org/

LICENSE=	GPLv2

USES=		java zip
JAVA_VERSION=	17+

DATADIR=	${PREFIX}/share/java/${PKGBASE}

DESKTOP_ENTRIES="Squirrel-SQL Client" \
		"${COMMENT}" \
		"${DATADIR}/icons/acorn.png" \
		"squirrel-sql" \
		"Development;Database;Java;" \
		false
EXTRACT_BEFORE_ARGS=	-qo \
			-x '*.bat' \
			-x '*.sh' \
			-x '${DISTNAME}/icons/acorn.png.bak.png' \
			-x '${DISTNAME}/mac' \
			-x '${DISTNAME}/squirrelcli/*' \
			-x '${DISTNAME}/squirrelcli'
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	squirrel-sql

WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/squirrel-sql ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
