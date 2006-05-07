# New ports collection makefile for:	kxmleditor
# Date created:		15 July 2001
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kxmleditor
PORTVERSION=	1.1.4
PORTREVISION=	3
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	XML editor for KDE

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' -e "s,-lpthread,${PTHREAD_LIBS},g" \
	${WRKSRC}/${CONFIGURE_SCRIPT}

.if ${ARCH} == "ia64"
BROKEN=	"Does not compile on ia64"
.endif

.include <bsd.port.post.mk>
