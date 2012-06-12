# New ports collection makefile for:	autotrace
# Date created:		12 April 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	autotrace
PORTVERSION=	0.31.1
PORTREVISION=	22
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/AutoTrace/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert bitmap to vector graphics

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
    		MagickWand.5:${PORTSDIR}/graphics/ImageMagick

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include/libpng15

MAN1=		autotrace.1

OPTIONS_DEFINE=	MING PSTOEDIT
OPTIONS_DEFAULT=	PSTOEDIT
MING_DESC=	Enable swf interface
PSTOEDIT_DESC=	Convert postscript to other formats

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSETUIDMING}
LIB_DEPENDS+=	ming.5:${PORTSDIR}/graphics/ming
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/ming
.endif

.if ${PORT_OPTIONS:MPSTOEDIT}
LIB_DEPENDS+=	pstoedit.0:${PORTSDIR}/graphics/pstoedit
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.if ${PORT_OPTIONS:MPSTOEDIT}
	@${REINPLACE_CMD} -e '/$$PSTOEDIT_CONFIG/  s|--version|--modversion| ; \
		s|$$PSTOEDIT_CONFIG $$pstoedit_args|pkg-config pstoedit| ; \
		/^PSTOEDIT_CONFIG=/ s|=.*$$|=pkg-config| ' ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
