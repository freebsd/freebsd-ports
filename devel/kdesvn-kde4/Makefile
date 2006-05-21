# New ports collection makefile for:	kdesvn
# Date created:				08 April 2006
# Whom:					Yuan Jue <yuanjue@yuanjue.net>
#
# $FreeBSD$

PORTNAME=	kdesvn
PORTVERSION=	0.8.4
CATEGORIES=	devel kde
MASTER_SITES=	http://www.alwins-world.de/programs/download/${PORTNAME}/ \
		http://www.yuanjue.net/download/

MAINTAINER=	yuanjue@yuanjue.net
COMMENT=	KDE frontend for Subversion

EXTRA_PATCHES=	${PORTSDIR}/x11/kde3/files/extrapatch-old_configure

LIB_DEPENDS+=	apr-1:${PORTSDIR}/devel/apr-svn \
		svn_client-1:${PORTSDIR}/devel/subversion \
		neon:${PORTSDIR}/www/neon

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS+=--with-apr-config=apr-1-config \
		--with-apu-config=apu-1-config

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
