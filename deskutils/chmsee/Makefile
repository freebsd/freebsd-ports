# New ports collection makefile for:	chmsee
# Date created:                		10 June 2006
# Whom:                    		Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	chmsee
PORTVERSION=	1.0.4
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A viewer for Microsoft Help "CHM" files

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib \
		gcrypt.16:${PORTSDIR}/security/libgcrypt

USE_GNOME=	gnomehack gnomehier libglade2
USE_GECKO=	firefox seamonkey xulrunner
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gecko=${GECKO}

MAN1=		chmsee.1

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
