# New ports collection makefile for:	lsysexp
# Date created:				22 Apr 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	lsysexp
PORTVERSION=	0.67
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://coscorrosa.com/programs/${PORTNAME}/download/

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A GTK based program for viewing and creating L-system fractals

WRKSRC=		${WRKDIR}/lsysexp-0.67

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|-DGTK_DISABLE_DEPRECATED||' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
