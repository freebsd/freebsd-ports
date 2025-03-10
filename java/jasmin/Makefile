PORTNAME=	jasmin
PORTVERSION=	2.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	java lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Assembler Interface
WWW=		https://jasmin.sourceforge.net/

USES=		dos2unix java:ant,run zip
DOS2UNIX_REGEX=	.*\.(txt|xml|j|class|java|mf|css|bnf|html)
JAVA_VERSION=	8

ALL_TARGET=	jasmin

SUB_FILES=	jasmin.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_DATA} ${WRKSRC}/jasmin.jar ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_SCRIPT} ${WRKDIR}/jasmin.sh ${STAGEDIR}${PREFIX}/bin/jasmin
	@${MKDIR} ${STAGEDIR}${DOCDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
