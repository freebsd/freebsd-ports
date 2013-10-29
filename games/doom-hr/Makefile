# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	hr
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.planetmirror.com/pub/idgames/themes/hr/ \
		ftp://ftp.fu-berlin.de/pc/msdos/games/idgames/themes/hr/ \
		ftp://ftp.ntua.gr/pub/vendors/idgames/themes/hr/ \
		http://ftp.sunet.se/pub/pc/games/idgames/themes/hr/ \
		ftp://3darchives.in-span.net/pub/idgames/themes/hr/
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
DISTFILES=	${PORTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hell Revealed is a megawad, a 32-level replacement for DooM II

USE_ZIP=	yes
USE_CRLF=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DEMO_NM DEMO_UV DOCS
OPTIONS_DEFAULT=	DEMO_NM DEMO_UV
DEMO_NM_DESC=	Install demos with -nomonsters
DEMO_UV_DESC=	Install Ultra-Violence demos

DATADIR=	${DMDIR}/${PORTNAME}

NO_STAGE=	yes
post-extract:
	@(cd ${WRKDIR} && ${SH} ${SCRIPTDIR}/lowercase.sh)

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEMO_NM}
DISTFILES+=	hrhelp${EXTRACT_SUFX}
PLIST_SUB+=	DEMO_NM=""
.else
PLIST_SUB+=	DEMO_NM="@comment "
.endif

.if ${PORT_OPTIONS:MDEMO_UV}
DISTFILES+=	hruvlmp2${EXTRACT_SUFX}
PLIST_SUB+=	DEMO_UV=""
.else
PLIST_SUB+=	DEMO_UV="@comment "
.endif

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.wad ${DATADIR}
.if ${PORT_OPTIONS:MDEMO_NM} || !empty(PORT_OPTIONS:MDEMO_UV)
	${INSTALL_DATA} ${WRKSRC}/*.lmp ${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
