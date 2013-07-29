# Created by: Brad Hendrickse <bradh@iafrica.com>
# $FreeBSD$

PORTNAME=	gifsicle
PORTVERSION=	1.71
CATEGORIES=	graphics
MASTER_SITES=	http://www.lcdf.org/gifsicle/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Manipulates GIF images and animations

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

MAN1=		gifdiff.1 gifsicle.1

PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MX11}
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=	--without-x --disable-gifview
.else
USE_XORG=	x11
MAN1+=		gifview.1
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
