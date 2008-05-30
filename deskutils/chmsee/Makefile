# New ports collection makefile for:	chmsee
# Date created:                		10 June 2006
# Whom:                    		Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	chmsee
PORTVERSION=	1.0.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://download.gro.clinux.org/chmsee/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A viewer for Microsoft Help "CHM" files

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib

USE_GNOME=	gnomehack gnomehier gnometarget libglade2
WANT_GNOME=	yes
USE_GECKO=	firefox mozilla seamonkey
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

MAN1=		chmsee.1

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
