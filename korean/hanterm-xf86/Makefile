# New ports collection makefile for:	hanterm-xf86
# Date created:		22 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hanterm
PORTVERSION=	2.0.5.173
PORTREVISION=	1
CATEGORIES=	korean x11
MASTER_SITES=	http://kldp.net/frs/download.php/282/
PKGNAMESUFFIX=	-xf
DISTNAME=	hanterm${PKGNAMESUFFIX}-2.0.5-173

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	X11R6-based xterm hacked for managing Korean languages

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf

CONFLICTS=	ko-hanterm-3.*
USE_ICONV=	yes
USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-boxchar --enable-ansi-color \
			--enable-256-color --enable-chat --enable-now-chat
CONFIGURE_ENV+=		LIBS="${LDFLAGS} -L${LOCALBASE}/lib -liconv" \
			CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAN1=		hanterm.1

pre-install:
	${MKDIR} ${PREFIX}/share/hangul_keyboard
	${CAT} ${FILESDIR}/defaultfont.ad >> ${WRKSRC}/Hanterm.ad

.include <bsd.port.mk>
