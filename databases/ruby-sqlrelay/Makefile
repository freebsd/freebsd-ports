# New ports collection makefile for:	Ruby module for SQL Relay
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
CATEGORIES=	databases ruby
MASTER_SITES=	# none
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Ruby module to access to SQL Relay

EXTRACT_DEPENDS=	${NONEXISTENT}:${SQLRELAY_PORTDIR}:patch
LIB_DEPENDS=	sqlrclient.0:${SQLRELAY_PORTDIR}

BROKEN=		"Does not install"

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/sqlrelay.so
USE_RUBY=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src/api/ruby
INSTALL_WRKSRC=	${BUILD_WRKSRC}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${SQLRELAY_CONFIGURE_ARGS} \
		--with-ruby-prefix="${LOCALBASE}"
MAKE_ARGS=	RUBY="${RUBY}"
ALL_TARGET=	sqlrelay.so

.include "${.CURDIR}/../sqlrelay/Makefile.common"

.if ${PORTVERSION} == 0.34.3
PORTREVISION?=	1
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -fs `${SQLRELAY_WRKSRC_CMD}` ${WRKSRC}
	${RM} -f ${WRKSRC}/config.cache
	${CP} ${TEMPLATES}/config.sub ${WRKSRC}
	${CP} ${TEMPLATES}/config.guess ${WRKSRC}

do-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/sqlrelay.so ${RUBY_SITEARCHLIBDIR}/

.include <bsd.port.mk>
