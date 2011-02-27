# New ports collection makefile for:	doom-hr
# Date created:				21 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

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

OPTIONS=	DEMO_NM "Install demos with -nomonsters" on \
		DEMO_UV "Install Ultra-Violence demos" on

DATADIR=	${DMDIR}/${PORTNAME}

post-extract:
	@(cd ${WRKDIR} && ${SH} ${SCRIPTDIR}/lowercase.sh)

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DEMO_NM)
DISTFILES+=	hrhelp${EXTRACT_SUFX}
PLIST_SUB+=	DEMO_NM=""
.else
PLIST_SUB+=	DEMO_NM="@comment "
.endif

.if !defined(WITHOUT_DEMO_UV)
DISTFILES+=	hruvlmp2${EXTRACT_SUFX}
PLIST_SUB+=	DEMO_UV=""
.else
PLIST_SUB+=	DEMO_UV="@comment "
.endif

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.wad ${DATADIR}
.if !defined(WITHOUT_DEMO_NM) || !defined(WITHOUT_DEMO_UV)
	${INSTALL_DATA} ${WRKSRC}/*.lmp ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
