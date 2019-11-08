# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	gtkperf
PORTVERSION=	0.40
PORTREVISION=	10
CATEGORIES=	benchmarks
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Measure your system's GTK+ performance

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		gmake gnome pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 gnomeprefix

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext iconv
NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LDFLAGS=	-L${LOCALBASE}/lib
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
