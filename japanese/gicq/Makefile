# New ports collection makefile for:	gicq
# Version required:		0.33
# Date Created:			31 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $Id: Makefile,v 1.4 1998/12/11 02:30:33 flathill Exp $
#

DISTNAME=	gicq-0.33
PKGNAME=	ja-gicq-0.33
CATEGORIES=	japanese net
MASTER_SITES=	ftp://ftp.korsoft.com/pub/gicq/

PATCH_SITES=	http://www.freebsd.org/~flathill/distfiles/ \
		http://www-nagao.kuee.kyoto-u.ac.jp/member/taku/soft/
PATCHFILES=	gicq-0.33ja.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	flathill@FreeBSD.ORG

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12	\
		icq.0:${PORTSDIR}/japanese/libicq

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --disable-nls
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		LIBS="-lxpg4"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/gicq ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gicq
	${INSTALL_DATA} ${WRKSRC}/doc/index.html ${PREFIX}/share/doc/gicq
.endif

.include <bsd.port.mk>
