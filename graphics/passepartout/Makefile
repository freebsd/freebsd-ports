# New ports collection makefile for:	passepartout
# Date created:				11st Sep 2003
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	passepartout
PORTVERSION=	0.3
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.stacken.kth.se/project/pptout/files/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DTP application for X

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2 \
		xml\\+\\+-0.1:${PORTSDIR}/textproc/libxml++
RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnometarget
USE_LIBTOOL=	yes

MAN=	xml2ps.1 passepartout.1x

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=  ${PATCHDIR}/extra-patch-old_cxx
.endif

# Fix for recent libxml++ API change
post-patch:
	@${FIND} ${WRKSRC}/src/pptout -name *.cc \
		| ${GREP} -v -E 'pagesel|undodialog' \
		| ${XARGS} ${REINPLACE_CMD} \
			-e 's|add_attribute|set_attribute|' \
			-e 's|add_content|add_child_text|'

.include <bsd.port.post.mk>
