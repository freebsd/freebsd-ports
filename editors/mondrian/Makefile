# New ports collection makefile for:	mondrian
# Date created:		2007-01-13
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	mondrian
PORTVERSION=	1.0.b8
PORTREVISION=	1
CATEGORIES=	editors ruby
MASTER_SITES=	http://www.mondrian-ide.com/download/ \
		LOCAL/nivit/${PORTNAME}/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/.b/beta/}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Mondrian Ruby IDE

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/fox12.so:${PORTSDIR}/x11-toolkits/ruby-fox12

NO_BUILD=	yes
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	RUBY=${RUBY}

FIND_DIRS=	-type d
FIND_DATA=	-type f

RM_OPTS=	-f
RM_FILES=	LICENSE CHANGELOG

post-extract:
	@cd ${WRKSRC} && ${RM} ${RM_OPTS} ${RM_FILES}

do-install:
	@cd ${WRKSRC} && ${FIND} . ${FIND_DIRS} -exec ${MKDIR} ${DATADIR}/{} ";"
	@cd ${WRKSRC} && ${FIND} . ${FIND_DATA} -exec ${INSTALL_DATA} {} ${DATADIR}/{} ";"
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
