# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jin
PORTVERSION=	2.14.1
PORTREVISION=	4
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Graphical client for chess servers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/src/free/jin/legal/copyright.txt

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${JAVAJARDIR}/bsh.jar:lang/bsh

USES=		dos2unix
DOS2UNIX_GLOB=	*.java *.txt
USE_JAVA=	yes
USE_ANT=	yes

MAKE_ARGS+=	-lib ${JAVAJARDIR}/bsh.jar

SUB_FILES=	${PORTNAME}
SUB_LIST=	JINJAR=${JINJAR:Q}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

EXTRACT_AFTER_ARGS=	--exclude 'bsh*.jar'	\
			--exclude os-specific/unix/jin	\
			--exclude jgoodies-windows.jar

JINJAR=	${PORTNAME}.jar

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${FIND} ${WRKSRC} -empty -delete
	cd ${WRKSRC}/build && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
