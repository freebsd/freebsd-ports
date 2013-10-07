# Created by: ijliao
# $FreeBSD$

PORTNAME=	lafontaine
PORTVERSION=	0.4.1
PORTREVISION=	8
CATEGORIES=	lang
MASTER_SITES=	http://www.nongnu.org/lafontaine/archives/
DISTNAME=	${PORTNAME}_0.4-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical logo interpreter

WRKSRC=		${WRKDIR}/${PORTNAME}-0.4

USES=		pathfix gmake pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
LDFLAGS+=	-lm

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
