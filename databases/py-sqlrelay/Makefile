# New ports collection makefile for:	Python module for SQL Relay
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	# none
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python modules to access to SQL Relay

EXTRACT_DEPENDS=	${NONEXISTENT}:${SQLRELAY_PORTDIR}:patch
LIB_DEPENDS=	sqlrclient.0:${SQLRELAY_PORTDIR}

USE_PYTHON=	yes
USE_PERL5_BUILD=yes

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src/api/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREADINCLUDES="${PTHREAD_CFLAGS}" \
		PTHREADLIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	${SQLRELAY_CONFIGURE_ARGS} \
		--with-python-prefix="${LOCALBASE}"

.include "${.CURDIR}/../sqlrelay/Makefile.common"

.include <bsd.port.pre.mk>

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -fs `${SQLRELAY_WRKSRC_CMD}` ${WRKSRC}
	${RM} -f ${WRKSRC}/config.cache

post-patch:
	${PERL} -i -p \
		-e 's,"2\.1" "2\.0" "1\.6" "1\.5",${PYTHON_VERSION:S/^python//},g;' \
			${WRKSRC}/configure
	${CP} ${TEMPLATES}/config.sub ${WRKSRC}
	${CP} ${TEMPLATES}/config.guess ${WRKSRC}

.include <bsd.port.post.mk>
