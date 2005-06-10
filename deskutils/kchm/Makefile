# New ports collection makefile for:	kchm
# Date created:				19 March 2005
# Whom:					pypt
#
# $FreeBSD$
#

PORTNAME=	kchm
PORTVERSION=	0.6.5
CATEGORIES=	deskutils kde
MASTER_SITES=	http://mesh.dl.sourceforge.net/sourceforge/kchmnew/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	shirshegsm@gmail.com
COMMENT=	A KDE viewer for CHM files

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib

USE_BZIP2=		yes
USE_KDEBASE_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL_INC_VER=	15

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Does not compile"
.endif

.include <bsd.port.post.mk>
