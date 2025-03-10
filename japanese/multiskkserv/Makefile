PORTNAME=	multiskkserv
DISTVERSION=	20240224
CATEGORIES=	japanese

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Multiple dictionary server for the SKK
WWW=		https://github.com/sina-ht/multiskkserv/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/${SKKDIR}/SKK-JISYO.L.cdb:japanese/skk-jisyo-cdb \
		${LOCALBASE}/${SKKDIR}/SKK-JISYO.jawiki.cdb:japanese/skk-jawiki

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	sina-ht
GH_TAGNAME=	2ffe7cd

SKKDIR?=	share/skk
SKKJISYO_TYPE?=	L JIS2 JIS3_4 jawiki

USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	SKKDICS="${SKKJISYO_TYPE:S/^/${PREFIX}\/${SKKDIR}\/SKK-JISYO./:S/$/.cdb/}"

PLIST_FILES=	bin/skkdic-p2cdb sbin/multiskkserv sbin/multiskkserv-ctl

OPTIONS_DEFINE=		CDB
OPTIONS_DEFAULT=	CDB
CDB_DESC=		Use databases/cdb instead of bundled tinycdb
CDB_EXTRACT_DEPENDS=	${NONEXISTENT}:databases/cdb:build
CDB_CONFIGURE_ON=	--with-cdb=`${MAKE} -C ${PORTSDIR}/databases/cdb -V WRKSRC`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/skkdic-p2cdb ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/src && ${INSTALL_PROGRAM} multiskkserv multiskkserv-ctl \
		${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
