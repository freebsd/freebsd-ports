# New ports collection makefile for:	fastresolve
# Date created:		11 June 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	fastresolve
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pix.net/staff/djm/sw/dist/

MAINTAINER=	verm@drunkmonk.net

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3 \
		adns.1:${PORTSDIR}/net/adns

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	-a
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CXXFLAGS="-I${LOCALBASE}/include/db3 -I${LOCALBASE}/include"

MAN1=	dns-terror.1 btree-dump.1 convert-dom-db.1 convert-ip-db.1 \
	expire-ip-db.1 getdominfo.1 rebuild-dom-db.1 rebuild-ip-db.1 \
	reresolve.1 make-report.1

.include <bsd.port.pre.mk>

pre-configure:
	@(cd ${WRKSRC} && aclocal14)

.include <bsd.port.post.mk>
