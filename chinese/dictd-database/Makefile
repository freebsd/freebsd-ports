# New ports collection makefile for:	dict-zh
# Date created:		25 Oct 1999
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dictd-database
PORTVERSION=	1.5
CATEGORIES=	chinese textproc
MASTER_SITES=	ftp://freebsd.csie.ntu.edu.tw/users/rafan/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/dictd-database/
DISTNAME=	dict-zh-${PORTVERSION}

MAINTAINER=	rafan@infor.org
COMMENT=	A Chinese <-> English dictd words database

BUILD_DEPENDS=	${LOCALBASE}/bin/dictfmt:${PORTSDIR}/textproc/dictfmt \
		${LOCALBASE}/bin/dictzip:${PORTSDIR}/net/dictd

BROKEN=		Does not build

USE_LIBTOOL_VER=	13
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_REINPLACE=	yes

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/configure

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502110
BUILD_DEPENDS+=	${LOCALBASE}/share/locale/zh_TW.UTF-8/LC_CTYPE:${PORTSDIR}/misc/utf8locale
.endif

.include <bsd.port.post.mk>
