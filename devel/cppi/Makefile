# New ports collection makefile for:	cppi
# Date created:		2006-11-05
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	cppi
PORTVERSION=	1.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A tool to indent the C preprocessor directives

USE_XZ=		yes
USE_GETTEXT=	yes                                                             
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=		cppi.1

.ifndef	WITHOUT_NLS
USE_GETTEXT=    yes                                                             
PLIST_SUB+=	NLS=""
.else                                                                           
CONFIGURE_ARGS+=--disable-nls                                                   
PLIST_SUB+=	NLS="@comment "
.endif                                                                          

post-patch:
	@${REINPLACE_CMD} -e 's:(libdir)/lib:(libdir):' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
