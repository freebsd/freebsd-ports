# New ports collection makefile for:   dedit
# Date created:        26 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dedit
PORTVERSION=	0.6.2.3
CATEGORIES=	editors gnome
MASTER_SITES=	ftp://ftp.debian.org/debian/pool/main/d/dedit/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgiconv"

MAN1=		dedit.1
MANLANG=	"" ja

pre-patch:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|dedit.ja.1||'
	@find ${WRKSRC} -name "*.c" | xargs ${PERL} -pi -e \
		's|<iconv.h>|<giconv.h>|g'

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/dedit.ja.1 ${MANPREFIX}/man/ja/man1/dedit.1

.include <bsd.port.mk>
