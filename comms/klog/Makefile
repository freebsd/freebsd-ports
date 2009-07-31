# New ports collection makefile for:	klog
# Date created:		2004-07-05
# Whom:			Matt Dawson <matt@mattsnetwork.co.uk>
#
# $FreeBSD$

PORTNAME=	klog
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	BERLIOS

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	A ham radio logging application for KDE

LIB_DEPENDS=	hamlib.2:${PORTSDIR}/comms/hamlib

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262:env automake:19:env libtool:15:env
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

post-extract:
	@${RM} -f ${WRKSRC}/po/gl.po

pre-configure:
	@cd ${WRKSRC} \
		&& ${RM} -f admin/libtool.m4.in admin/ltmain.sh \
		&& ${CP} -f ${LIBTOOL_M4} admin/libtool.m4.in \
		&& ${CP} -f ${LTMAIN} admin/ltmain.sh \
		&& ${SETENV} ${MAKE_ENV} ${GMAKE} -f admin/Makefile.common

.include <bsd.port.mk>
