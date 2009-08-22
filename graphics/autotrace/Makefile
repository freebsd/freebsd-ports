# New ports collection makefile for:	autotrace
# Date created:		12 April 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	autotrace
PORTVERSION=	0.31.1
PORTREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/AutoTrace/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert bitmap to vector graphics

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
    		MagickWand.2:${PORTSDIR}/graphics/ImageMagick

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/ming"

MAN1=		autotrace.1

OPTIONS=	MING "Enable swf interface" on \
		PSTOEDIT "Convert postscript to other formats" on

.include <bsd.port.pre.mk>

.if !defined (WITHOUT_MING)
LIB_DEPENDS+=	ming.4:${PORTSDIR}/graphics/ming
CONFIGURE_ENV?=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/ming"
.endif

.if !defined (WITHOUT_PSTOEDIT)
LIB_DEPENDS+=	pstoedit.0:${PORTSDIR}/graphics/pstoedit
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.if defined (WITH_PSTOEDIT)
	@${REINPLACE_CMD} -e '/$$PSTOEDIT_CONFIG/  s|--version|--modversion| ; \
		s|$$PSTOEDIT_CONFIG $$pstoedit_args|pkg-config pstoedit| ; \
		/^PSTOEDIT_CONFIG=/ s|=.*$$|=pkg-config| ' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
