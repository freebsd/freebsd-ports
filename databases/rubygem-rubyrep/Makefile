# New ports collection makefile for:	rubygem-rubyrep
# Date created:		2011-07-30
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		rubyrep
PORTVERSION=		1.2.0
CATEGORIES=		databases rubygems
MASTER_SITES=		RG

MAINTAINER=		ltning@anduin.net
COMMENT=		Multi-master replication and sync for MySQL and PostgreSQL

BUILD_DEPENDS=	rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-activerecord>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activerecord
RUN_DEPENDS+=	flog>=0:${PORTSDIR}/sysutils/flog \
		rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-activerecord>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activerecord

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

USE_RC_SUBR=	rubyrep

OPTIONS =	MYSQL "Enable MySQL support" off \
		PGSQL "Enable PostgreSQL support" on

PLIST_FILES=	bin/rubyrep

.include <bsd.port.options.mk>

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	ruby-mysql>=0:${PORTSDIR}/databases/ruby-mysql
.endif

.include <bsd.port.mk>
