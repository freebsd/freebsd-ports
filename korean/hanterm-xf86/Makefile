# New ports collection makefile for:	hanterm-xf86
# Date created:		22 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hanterm
PORTVERSION=	2.0.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	korean x11
MASTER_SITES=	http://www.kr.FreeBSD.org/~hwang/hanterm/ \
		http://hanterm.org/download/hanterm-xf/
PKGNAMESUFFIX=	-xf
DISTNAME=	hanterm${PKGNAMESUFFIX}-${PORTVERSION}

PATCH_SITES=	ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/
PATCHFILES=	hanterm-xf-2.0.0.patch3
PATCH_DIST_STRIP=	-p1

MAINTAINER=	cjh@FreeBSD.org

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf
#		${LOCALBASE}/share/iconv/johab.cct:${PORTSDIR}/converters/iconv-extra

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-boxchar --enable-ansi-color \
			--enable-256-color --enable-chat --enable-now-chat
CONFIGURE_ENV+=		LIBS="${LDFLAGS} -L${LOCALBASE}/lib -liconv" \
			CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
MAN1=		hanterm.1 resize.1

pre-install:
	${MKDIR} ${PREFIX}/share/hangul_keyboard
	${CAT} ${FILESDIR}/defaultfont.ad >> ${WRKSRC}/Hanterm.ad

.include <bsd.port.mk>
