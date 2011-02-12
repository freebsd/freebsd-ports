# New ports collection makefile for:	ipa_sdb
# Date created:				27 December 2005
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa_sdb
PORTVERSION=	1.1
CATEGORIES=	databases
MASTER_SITES=	SF/ipa-system/modules/ipa_sdb

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
COMMENT=	IPA simple database module

BUILD_DEPENDS=	${LOCALBASE}/include/ipa_mod.h:${PORTSDIR}/sysutils/ipa

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS=	AUTORULES "Enable dynamic rules support" on \
		RULES "Enable static rules support" on \
		LIMITS "Enable limits support" on \
		THRESHOLDS "Enable thresholds support" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_AUTORULES)
CONFIGURE_ARGS+=	--disable-autorules
.endif

.if defined(WITHOUT_RULES)
CONFIGURE_ARGS+=	--disable-rules
.endif

.if defined(WITHOUT_LIMITS)
CONFIGURE_ARGS+=	--disable-limits
.endif

.if defined(WITHOUT_THRESHOLDS)
CONFIGURE_ARGS+=	--disable-thresholds
.endif

.include <bsd.port.pre.mk>

PLIST_FILES=	bin/ipa_sdb_dump include/ipa_sdb.h include/ipa_sdb_config.h \
		lib/ipa_db_sdb.so lib/ipa_st_sdb.so \
		lib/ipa_db_sdb.la lib/ipa_st_sdb.la

MAN5=		ipa_sdb.5
MAN8=		ipa_db_sdb.8 ipa_st_sdb.8 ipa_sdb_dump.8
MANLANG=	"" ru.KOI8-R

.include <bsd.port.post.mk>
