# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ceylon
PORTVERSION=	1.3.3
CATEGORIES=	lang java
MASTER_SITES=	http://downloads.ceylon-lang.org/cli/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ceylon is a language for writing large programs in teams

LICENSE=	APACHE20 GPLv2
LICENSE_COMB=	multi

USES=		zip
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_RUN=	yes

PORTDATA=	*

CEYLON_SCRIPTS=	ceylon ceylon-sh-setup
CEYLON_DIRS=	contrib lib repo samples templates

do-install:
	${RM} ${WRKSRC}/bin/*.bat

	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/* ${STAGEDIR}/${MAN1PREFIX}/man/man1

	${MKDIR} ${STAGEDIR}${DATADIR}
.for d in ${CEYLON_DIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR}
.endfor

	cd ${WRKSRC} && ${COPYTREE_BIN} bin ${STAGEDIR}${DATADIR}
.for s in ${CEYLON_SCRIPTS}
	${LN} -s ${DATADIR}/bin/${s} ${STAGEDIR}/${PREFIX}/bin/${s}
.endfor

.include <bsd.port.mk>
