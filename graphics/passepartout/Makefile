# New ports collection makefile for:	passepartout
# Date created:				11st Sep 2003
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	passepartout
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.stacken.kth.se/project/pptout/files/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	passepartout-0.2-assert.patch \
		passepartout-0.2-thread.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DTP application for X

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2 \
		xml\\+\\+-0.1:${PORTSDIR}/textproc/libxml++
RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gnomehack
USE_LIBTOOL=	yes

# Fix for recent libxml++ API change
post-patch:
	@${FIND} ${WRKSRC}/src/pptout -name *.cc \
		| grep -v -E 'pagesel|undodialog' \
		| ${XARGS} ${REINPLACE_CMD} -e \
			's|add_attribute|set_attribute|'

.include <bsd.port.mk>
