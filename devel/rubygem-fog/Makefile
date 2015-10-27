# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog
PORTVERSION=	1.35.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby cloud services library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-aliyun>=0:${PORTSDIR}/net/rubygem-fog-aliyun \
		rubygem-fog-atmos>=0:${PORTSDIR}/net/rubygem-fog-atmos \
		rubygem-fog-aws>=0.6.0:${PORTSDIR}/net/rubygem-fog-aws \
		rubygem-fog-brightbox>=0.4:${PORTSDIR}/net/rubygem-fog-brightbox \
		rubygem-fog-core>=1.32:${PORTSDIR}/devel/rubygem-fog-core \
		rubygem-fog-dynect>=0.0.2:${PORTSDIR}/net/rubygem-fog-dynect \
		rubygem-fog-ecloud>=0.1:${PORTSDIR}/net/rubygem-fog-ecloud \
		rubygem-fog-google>=0.1.1:${PORTSDIR}/net/rubygem-fog-google \
		rubygem-fog-json>=0:${PORTSDIR}/devel/rubygem-fog-json \
		rubygem-fog-local>=0:${PORTSDIR}/net/rubygem-fog-local \
		rubygem-fog-powerdns>=0.1.1:${PORTSDIR}/net/rubygem-fog-powerdns \
		rubygem-fog-profitbricks>=0:${PORTSDIR}/net/rubygem-fog-profitbricks \
		rubygem-fog-radosgw>=0.0.2:${PORTSDIR}/net/rubygem-fog-radosgw \
		rubygem-fog-riakcs>=0:${PORTSDIR}/net/rubygem-fog-riakcs \
		rubygem-fog-sakuracloud>=0.0.4:${PORTSDIR}/net/rubygem-fog-sakuracloud \
		rubygem-fog-serverlove>=0:${PORTSDIR}/net/rubygem-fog-serverlove \
		rubygem-fog-softlayer>=0:${PORTSDIR}/net/rubygem-fog-softlayer \
		rubygem-fog-storm_on_demand>=0:${PORTSDIR}/net/rubygem-fog-storm_on_demand \
		rubygem-fog-terremark>=0:${PORTSDIR}/net/rubygem-fog-terremark \
		rubygem-fog-vmfusion>=0:${PORTSDIR}/net/rubygem-fog-vmfusion \
		rubygem-fog-voxel>=0:${PORTSDIR}/net/rubygem-fog-voxel \
		rubygem-fog-xenserver>=0:${PORTSDIR}/net/rubygem-fog-xenserver \
		rubygem-fog-xml>=0.1.1:${PORTSDIR}/textproc/rubygem-fog-xml \
		rubygem-ipaddress>=0.5:${PORTSDIR}/net/rubygem-ipaddress \
		rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/fog

.include <bsd.port.mk>
