# New ports collection makefile for:	rubygem-datamapper
# Date created:		28, Dec 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	datamapper
PORTVERSION=	1.0.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast, thread-safe, object-relational mapper

RUN_DEPENDS=	rubygem-dm-aggregates>=1.0.0:${PORTSDIR}/databases/rubygem-dm-aggregates \
	rubygem-dm-constraints>=1.0.0:${PORTSDIR}/databases/rubygem-dm-constraints \
	rubygem-dm-transactions>=1.0.0:${PORTSDIR}/databases/rubygem-dm-transactions \
	rubygem-dm-serializer>=1.0.0:${PORTSDIR}/databases/rubygem-dm-serializer \
	rubygem-dm-timestamps>=1.0.0:${PORTSDIR}/databases/rubygem-dm-timestamps \
	rubygem-dm-validations>=1.0.0:${PORTSDIR}/databases/rubygem-dm-validations \
	rubygem-dm-types>=1.0.0:${PORTSDIR}/databases/rubygem-dm-types

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
