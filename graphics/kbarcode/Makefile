# New ports collection makefile for:	kbarcode
# Date created:				05 July 2002
# Whom:					Andy Raffle <andy@digitalspecies.com>
#
# $FreeBSD$
#

PORTNAME=	kbarcode
PORTVERSION=	2.0.7
PORTREVISION=	5
CATEGORIES=	graphics kde
MASTER_SITES=	SF/${PORTNAME}/Stable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A barcode and label printing application for KDE

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_KDELIBS_VER=	3
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:22:env
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

pre-configure:
	@cd ${WRKSRC} \
		&& ${RM} -f admin/libtool.m4.in admin/ltmain.sh \
		&& ${CP} -f ${LIBTOOL_M4} admin/libtool.m4.in \
		&& ${CP} -f ${LTMAIN} admin/ltmain.sh \
		&& ${SETENV} ${MAKE_ENV} UNSERMAKE=no ${GMAKE} -f admin/Makefile.common

.include <bsd.port.mk>
