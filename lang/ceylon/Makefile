# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ceylon
PORTVERSION=	1.2.2
CATEGORIES=	lang java
MASTER_SITES=	http://downloads.ceylon-lang.org/cli/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Ceylon is a language for writing large programs in teams

LICENSE=	APACHE20 GPLv2
LICENSE_COMB=	multi

NO_BUILD=	yes
USES=	zip

USE_JAVA=	yes
JAVA_VERSION=	1.7+
JAVA_RUN=	yes

PORTDATA=	*

CEYLON_SCRIPTS=	ceylon ceylon-sh-setup
CEYLON_DIRS=	contrib lib repo samples templates

.include <bsd.port.pre.mk>

do-install:
	${RM} -f ${WRKSRC}/bin/*.bat

	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/* ${STAGEDIR}/${MAN1PREFIX}/man/man1

	${MKDIR} ${STAGEDIR}${DATADIR}
.for d in ${CEYLON_DIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR}
.endfor

	cd ${WRKSRC} && ${COPYTREE_BIN} bin ${STAGEDIR}${DATADIR}
.for s in ${CEYLON_SCRIPTS}
	${LN} -s ${DATADIR}/bin/${s} ${STAGEDIR}/${PREFIX}/bin/${s}
.endfor

.include <bsd.port.post.mk>
