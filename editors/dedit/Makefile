# New ports collection makefile for:   dedit
# Date created:        26 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dedit
PORTVERSION=	0.5.8
CATEGORIES=	editors gnome
MASTER_SITES=	ftp://ftp.debian.org/debian/dists/unstable/main/source/editors/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	iconv.0:${PORTSDIR}/converters/iconv \
		gnome.4:${PORTSDIR}/x11/gnomelibs

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOMAKE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASSE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
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
