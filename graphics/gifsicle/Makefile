# New ports collection makefile for:	gifsicle
# Date created:			19 December 1998
# Whom:				Brad Hendrickse <bradh@iafrica.com>
#
# $FreeBSD$
#

PORTNAME=	gifsicle
PORTVERSION=	1.55
CATEGORIES=	graphics
MASTER_SITES=	http://www.lcdf.org/gifsicle/

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Manipulates GIF images and animations

GNU_CONFIGURE=	yes

MAN1=		gifdiff.1 gifsicle.1

.if !defined(HAVE_UNISYS_LICENSE)
CONFIGURE_ARGS+=	--enable-ungif
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=	--without-x --disable-gifview
PLIST_SUB=	X11='@comment '
.else
USE_XORG=	x11
MAN1+=		gifview.1
PLIST_SUB=	X11=''
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
