# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	datamapper
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast, thread-safe, object-relational mapper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-dm-aggregates>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-aggregates \
		rubygem-dm-constraints>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-constraints \
		rubygem-dm-core>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-core \
		rubygem-dm-migrations>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-migrations \
		rubygem-dm-serializer>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-serializer \
		rubygem-dm-timestamps>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-timestamps \
		rubygem-dm-transactions>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-transactions \
		rubygem-dm-types>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-types \
		rubygem-dm-validations>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-validations

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
