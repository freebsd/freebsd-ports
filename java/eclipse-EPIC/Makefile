# New ports collection makefile for:	EPIC
# Date created:				28 Nov 2004
# Whom:					tux@pinguru.net
#
# $FreeBSD$
#

PORTNAME=	EPIC
PORTVERSION=	0.3.0
CATEGORIES=	java editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	e-p-i-c
PKGNAMEPREFIX=	eclipse-
DISTNAME=	${EPIC}_${PORTVERSION}_20040711

MAINTAINER=	tux@pinguru.net
COMMENT=	EPIC adds Perl support to the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${EPIC}

EPIC=		org.epic.updatesite
ECLIPSE=	${PREFIX}/eclipse

do-install:
	@${CP} -r ${WRKSRC}/features/*.jar ${ECLIPSE}/features
	@${CP} -r ${WRKSRC}/plugins/*.jar ${ECLIPSE}/plugins

post-install:
	@${FIND} -s ${WRKSRC}/features -name "*.jar" \
	  | ${SED} -ne 's,^${WRKSRC},${ECLIPSE:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s ${WRKSRC}/plugins -name "*.jar" \
	  | ${SED} -ne 's,^${WRKSRC},${ECLIPSE:S,^${PREFIX}/,,},p' >> ${TMPPLIST}

.include <bsd.port.mk>
