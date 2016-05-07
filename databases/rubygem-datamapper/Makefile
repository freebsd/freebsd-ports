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

RUN_DEPENDS=	rubygem-dm-aggregates>=${PORTVERSION}:databases/rubygem-dm-aggregates \
		rubygem-dm-constraints>=${PORTVERSION}:databases/rubygem-dm-constraints \
		rubygem-dm-core>=${PORTVERSION}:databases/rubygem-dm-core \
		rubygem-dm-migrations>=${PORTVERSION}:databases/rubygem-dm-migrations \
		rubygem-dm-serializer>=${PORTVERSION}:databases/rubygem-dm-serializer \
		rubygem-dm-timestamps>=${PORTVERSION}:databases/rubygem-dm-timestamps \
		rubygem-dm-transactions>=${PORTVERSION}:databases/rubygem-dm-transactions \
		rubygem-dm-types>=${PORTVERSION}:databases/rubygem-dm-types \
		rubygem-dm-validations>=${PORTVERSION}:databases/rubygem-dm-validations

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
