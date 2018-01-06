# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog
PORTVERSION=	1.42.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby cloud services library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-aliyun>=0.1.0:net/rubygem-fog-aliyun \
		rubygem-fog-atmos>=0:net/rubygem-fog-atmos \
		rubygem-fog-aws>=0.6.0:net/rubygem-fog-aws \
		rubygem-fog-brightbox>=0.4:net/rubygem-fog-brightbox \
		rubygem-fog-cloudatcost>=0.1.0:net/rubygem-fog-cloudatcost \
		rubygem-fog-core>=1.45:devel/rubygem-fog-core \
		rubygem-fog-digitalocean>=0.3.0:net/rubygem-fog-digitalocean \
		rubygem-fog-dnsimple>=1.0:net/rubygem-fog-dnsimple \
		rubygem-fog-dynect>=0.0.2:net/rubygem-fog-dynect \
		rubygem-fog-ecloud>=0.1:net/rubygem-fog-ecloud \
		rubygem-fog-google>=0.1.1:net/rubygem-fog-google \
		rubygem-fog-internet-archive>=0:net/rubygem-fog-internet-archive \
		rubygem-fog-joyent>=0:net/rubygem-fog-joyent \
		rubygem-fog-json>=0:devel/rubygem-fog-json \
		rubygem-fog-local>=0:net/rubygem-fog-local \
		rubygem-fog-openstack>=0:net/rubygem-fog-openstack \
		rubygem-fog-ovirt>=0:net/rubygem-fog-ovirt \
		rubygem-fog-powerdns>=0.1.1:net/rubygem-fog-powerdns \
		rubygem-fog-profitbricks>=0:net/rubygem-fog-profitbricks \
		rubygem-fog-rackspace>=0:net/rubygem-fog-rackspace \
		rubygem-fog-radosgw>=0.0.2:net/rubygem-fog-radosgw \
		rubygem-fog-riakcs>=0:net/rubygem-fog-riakcs \
		rubygem-fog-sakuracloud>=0.0.4:net/rubygem-fog-sakuracloud \
		rubygem-fog-serverlove>=0:net/rubygem-fog-serverlove \
		rubygem-fog-softlayer>=0:net/rubygem-fog-softlayer \
		rubygem-fog-storm_on_demand>=0:net/rubygem-fog-storm_on_demand \
		rubygem-fog-terremark>=0:net/rubygem-fog-terremark \
		rubygem-fog-vmfusion>=0:net/rubygem-fog-vmfusion \
		rubygem-fog-voxel>=0:net/rubygem-fog-voxel \
		rubygem-fog-vsphere>=0.4.0:net/rubygem-fog-vsphere \
		rubygem-fog-xenserver>=0:net/rubygem-fog-xenserver \
		rubygem-fog-xml>=0.1.1:textproc/rubygem-fog-xml \
		rubygem-ipaddress>=0.5:net/rubygem-ipaddress \
		rubygem-json>=2.0:devel/rubygem-json

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/fog

.include <bsd.port.mk>
