# New ports collection makefile for:	kexchange
# Date created:				17 October 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kexchange
PORTVERSION=	0.3.2
CATEGORIES=	finance kde
MASTER_SITES=	http://ftp.kde.com/Financial_Investment/Currency_Tools/KExchange/ \

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE currency converter

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
