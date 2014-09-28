# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	jpmobile
PORTVERSION=	4.1.2
CATEGORIES=	japanese www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Rails plugin for Japanese mobile-phones

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rails4>0:${PORTSDIR}/www/rubygem-rails4

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

OPTIONS_DEFINE=		GEOKIT IPADDRESSES TERMINFO
GEOKIT_DESC=		Run with geokit
IPADDRESSES_DESC=	IP address validation support
TERMINFO_DESC=		terminal information support

OPTIONS_DEFAULT=	IPADDRESSES TERMINFO

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}rubygem-

.if ${PORT_OPTIONS:MGEOKIT}
RUN_DEPENDS+=	rubygem-geokit>=1.5.0:${PORTSDIR}/graphics/rubygem-geokit
.endif

.if ${PORT_OPTIONS:MIPADDRESSES}
RUN_DEPENDS+=	ja-rubygem-jpmobile-ipaddresses>=0.0.1:${PORTSDIR}/japanese/rubygem-jpmobile-ipaddresses
.endif

.if ${PORT_OPTIONS:MTERMINFO}
RUN_DEPENDS+=	ja-rubygem-jpmobile-terminfo>=0.0.2:${PORTSDIR}/japanese/rubygem-jpmobile-terminfo
.endif

.include <bsd.port.post.mk>
