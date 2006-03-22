# New ports collection makefile for:	ipa_sdb
# Date created:				27 December 2005
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa_sdb
PORTVERSION=	1.0.1
CATEGORIES=	databases
MASTER_SITES=	http://ipa-system.sourceforge.net/modules/ipa_sdb/

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
COMMENT=	IPA simple database module

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

OPTIONS=	AUTORULES "Enable dynamic rules support" on \
		RULES "Enable static rules support" on \
		LIMITS "Enable limits support" on \
		THRESHOLDS "Enable thresholds support" on \
		DEBUG_INFO "Produce debugging information" off \
		MAN_KOI8_R "Install Russian manual pages" off

.include <bsd.port.pre.mk>

BUILD_DEPENDS=	${PREFIX}/include/ipa_mod.h:${PORTSDIR}/sysutils/ipa

PLIST_FILES=    bin/ipa_sdb_dump lib/ipa_db_sdb.so lib/ipa_st_sdb.so \
		include/ipa_sdb.h lib/ipa_db_sdb.la lib/ipa_st_sdb.la

.ifdef WITHOUT_AUTORULES
CONFIGURE_ARGS+= --disable-autorules
.endif

.ifdef WITHOUT_RULES
CONFIGURE_ARGS+= --disable-rules
.endif

.ifdef WITHOUT_LIMITS
CONFIGURE_ARGS+= --disable-limits
.endif

.ifdef WITHOUT_THRESHOLDS
CONFIGURE_ARGS+= --disable-thresholds
.endif

.ifdef WITH_DEBUG_INFO
STRIP=		# empty
CFLAGS+=	-g
.endif

MAN5=		ipa_sdb.5
MAN8=		ipa_db_sdb.8 ipa_st_sdb.8 ipa_sdb_dump.8
MANLANG=	""
.ifdef WITH_MAN_KOI8_R
MANLANG+=	ru.KOI8-R
.endif

do-install:
	cd ${WRKSRC}/src && make install
	cd ${WRKSRC}/man && make install-am
.ifdef WITH_MAN_KOI8_R
	cd ${WRKSRC}/man/ru.KOI8-R && make install
.endif

.include <bsd.port.post.mk>
