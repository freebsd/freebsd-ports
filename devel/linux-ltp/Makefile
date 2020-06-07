# $FreeBSD$

# Note that this port uses RPMs from openSUSE - CentOS doesn't seem
# to carry LTP packages.  For future updates, here's the openSUSE
# package site: https://build.opensuse.org/package/show/benchmark/ltp

PORTNAME=	ltp
PORTVERSION=	20200605
DISTVERSIONSUFFIX=	.b54247721-368.1
CATEGORIES=	devel
MASTER_SITES=	https://download.opensuse.org/repositories/benchmark:/ltp:/devel/%SUBDIR%/:DEFAULT,amd64,SOURCE
MASTER_SITE_SUBDIR=	SLE_15/x86_64/:DEFAULT,amd64 \
			SLE_15/src/:SOURCE

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Linux Test Project (SUSE Linux Enterprise 15)

LICENSE=	GPLv2+

ONLY_FOR_ARCHS=	amd64

USES=		linux:c7
USE_LINUX=	dosfstools libaio numactl-libs
USE_LINUX_RPM=	yes

.include <bsd.port.mk>
