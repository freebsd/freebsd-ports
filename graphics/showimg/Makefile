# ex:ts=8
# Ports collection makefile for:	showimg
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	showimg
PORTVERSION=	0.9.1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.jalix.org/projects/showimg/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A picture viewer designed to run under KDE 3.x

USE_BZIP2=	yes
USE_KDEBASE_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN1=		showimg.1

OPTIONS=	DIGIKAM "Digikam plugins support" off

.include <bsd.port.pre.mk>

.if defined(WITH_DIGIKAM)
LIB_DEPENDS+=	digikam:${PORTSDIR}/graphics/digikam
CONFIGURE_ARGS+=	--enable-digiKam-plugin
.endif

.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
