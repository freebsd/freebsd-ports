# ex:ts=8
# Ports collection makefile for:	showimg
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	showimg
PORTVERSION=	0.8.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.jalix.org/projects/showimg/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A picture viewer designed to run under KDE 3.x

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_KDEBASE_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN1=		showimg.1

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
