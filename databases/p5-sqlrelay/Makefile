# New ports collection makefile for:	Perl5 modules for SQL Relay
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	# none
PKGNAMEPREFIX=	p5-
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 modules to access to SQL Relay, including a DBD interface

EXTRACT_DEPENDS=	${NONEXISTENT}:${SQLRELAY_PORTDIR}:patch
LIB_DEPENDS=	sqlrclient.0:${SQLRELAY_PORTDIR}

BROKEN=		"Build fails"

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	Makefile.master
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${SQLRELAY_CONFIGURE_ARGS} \
		--with-perl-prefix="/usr"

MAN3=		DBD::SQLRelay.3 \
		Firstworks::SQLRConnection.3 \
		Firstworks::SQLRCursor.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include "${.CURDIR}/../sqlrelay/Makefile.common"

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -fs `${SQLRELAY_WRKSRC_CMD}` ${WRKSRC}
	${RM} -f ${WRKSRC}/config.cache
	${CP} ${TEMPLATES}/config.sub ${WRKSRC}
	${CP} ${TEMPLATES}/config.guess ${WRKSRC}

do-build:
	for dir in ${WRKSRC}/src/api/perl/*; do \
		cd $$dir && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${ALL_TARGET}; \
	done

do-install:
	for dir in ${WRKSRC}/src/api/perl/*; do \
		cd $$dir && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}; \
	done

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
