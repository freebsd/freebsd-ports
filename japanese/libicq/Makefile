# New ports collection makefile for:   libicq
# Version required:		0.33
# Date Created:			22 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $Id: Makefile,v 1.1.1.1 1998/11/19 07:33:02 flathill Exp $
#

DISTNAME=	libicq-0.33
PKGNAME=	ja-libicq-0.33
CATEGORIES=	japanese devel
MASTER_SITES=	ftp://ftp.korsoft.com/pub/gicq/

PATCH_SITES=	http://www.freebsd.org/~flathill/distfiles/ \
		http://www-nagao.kuee.kyoto-u.ac.jp/member/taku/soft/
PATCHFILES=	libicq-0.33ja.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	flathill@FreeBSD.ORG

LIB_DEPENDS=    glib12.1:${PORTSDIR}/devel/glib12

GNU_CONFIGURE=  yes
CONFIGURE_ENV=  GLIB_CONFIG="${PREFIX}/bin/glib12-config"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
