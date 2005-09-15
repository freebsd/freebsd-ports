# New ports collection makefile for:	klog
# Date created:		2004-07-05
# Whom:			Matt Dawson <matt@mattsnetwork.co.uk>
#
# $FreeBSD$

PORTNAME=	klog
PORTVERSION=	0.2.8
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://download.berlios.de/klog/

MAINTAINER=	az@az.inec.ru
COMMENT=	ADIF compatible logging application

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_KDELIBS_VER=3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
post-patch:
	@${FIND} ${WRKSRC} -name "*.cpp" -and -not -name "main.cpp"| \
	${XARGS} ${REINPLACE_CMD} -e "s|^};|}|;s|{};|{}|;s|;};|;}|g"
.endif

.include <bsd.port.post.mk>
