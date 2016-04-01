# Created by: Takahiro Morishita <morishita@skywing.org>
# $FreeBSD$

PORTNAME=	multiskkserv
PORTVERSION=	0.20020201
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://www3.big.or.jp/~sian/linux/products/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple dictionary server for the SKK

EXTRACT_DEPENDS=	${NONEXISTENT}:databases/cdb:build
RUN_DEPENDS=	${LOCALBASE}/${SKKDIR}/SKK-JISYO.${SKKJISYO_TYPE}.cdb:japanese/skk-jisyo-cdb

USES=		tar:bzip2

SKKDIR?=	share/skk
SKKJISYO_TYPE?=	L

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/0.//g}
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-cdb=`cd ${PORTSDIR}/databases/cdb; ${MAKE} -V WRKSRC`

PLIST_FILES=	bin/skkdic-p2cdb sbin/multiskkserv sbin/multiskkserv-ctl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/multiskkserv ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/multiskkserv-ctl ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/skkdic-p2cdb ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
