# New ports collection makefile for:   dedit
# Date created:        26 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dedit
PORTVERSION=	0.5.11
CATEGORIES=	editors gnome
MASTER_SITES=	ftp://ftp.debian.org/debian/dists/unstable/main/source/editors/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	iconv.1:${PORTSDIR}/converters/iconv

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASSE}/include" \
		LIBS="-L${LOCALBASE}/lib -liconv"

MAN1=		dedit.1
.if defined(KANJI)
MANLANG=	"" ja
.endif

post-install:
.if defined(KANJI)
	${INSTALL_MAN} ${WRKSRC}/doc/dedit.ja.1 \
	${PREFIX}/man/ja/man1/dedit.1
.endif

.include <bsd.port.mk>
