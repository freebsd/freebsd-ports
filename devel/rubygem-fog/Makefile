# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog
PORTVERSION=	1.25.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby cloud services library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-fog-brightbox>=0.4:${PORTSDIR}/devel/rubygem-fog-brightbox \
		rubygem-fog-core>=1.25:${PORTSDIR}/devel/rubygem-fog-core \
		rubygem-fog-json>=0:${PORTSDIR}/devel/rubygem-fog-json \
		rubygem-fog-profitbricks>=0:${PORTSDIR}/net/rubygem-fog-profitbricks \
		rubygem-fog-radosgw>=0.0.2:${PORTSDIR}/net/rubygem-fog-radosgw \
		rubygem-fog-sakuracloud>=0.0.4:${PORTSDIR}/net/rubygem-fog-sakuracloud \
		rubygem-fog-softlayer>=0:${PORTSDIR}/net/rubygem-fog-softlayer \
		rubygem-fog-terremark>=0:${PORTSDIR}/net/rubygem-fog-terremark \
		rubygem-fog-voxel>=0:${PORTSDIR}/net/rubygem-fog-voxel \
		rubygem-fog-vmfusion>=0:${PORTSDIR}/net/rubygem-fog-vmfusion \
		rubygem-fog-xml>=0.1.1:${PORTSDIR}/textproc/rubygem-fog-xml \
		rubygem-ipaddress>=0.5:${PORTSDIR}/net/rubygem-ipaddress \
		rubygem-nokogiri>=1.5.11:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-opennebula>=0:${PORTSDIR}/net/rubygem-opennebula

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/fog

.include <bsd.port.mk>
