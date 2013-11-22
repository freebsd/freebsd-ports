# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	delayed_job_data_mapper
DISTVERSION=	1.0.0.rc
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DataMapper backend for delayed_job

RUN_DEPENDS=	rubygem-delayed_job>=2.1:${PORTSDIR}/devel/rubygem-delayed_job \
		rubygem-dm-aggregates>=0:${PORTSDIR}/databases/rubygem-dm-aggregates \
		rubygem-dm-core>=0:${PORTSDIR}/databases/rubygem-dm-core \
		rubygem-dm-observer>=0:${PORTSDIR}/databases/rubygem-dm-observer

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-12-22

BROKEN=	delayed_job_data_mapper requires delayed_job (~> 2.1)

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

GEM_NAME=	${DISTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>
