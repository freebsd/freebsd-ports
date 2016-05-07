# Created by: Andrey Simonenko
# $FreeBSD$

PORTNAME=	ipa_sdb
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	SF/ipa-system/modules/ipa_sdb

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPA simple database module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/ipa_mod.h:sysutils/ipa

USES=		libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=		AUTORULES RULES LIMITS THRESHOLDS
OPTIONS_DEFAULT=	AUTORULES RULES LIMITS THRESHOLDS
AUTORULES_DESC=		Enable dynamic rules support
RULES_DESC=		Enable static rules support
LIMITS_DESC=		Enable limits support
THRESHOLDS_DESC=	Enable thresholds support

AUTORULES_CONFIGURE_OFF=	--disable-autorules
RULES_CONFIGURE_OFF=		--disable-rules
LIMITS_CONFIGURE_OFF=		--disable-limits
THRESHOLDS_CONFIGURE_OFF=	--disable-thresholds

.include <bsd.port.mk>
