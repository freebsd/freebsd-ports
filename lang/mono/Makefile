# New ports collection makefile for:   mono
# Date created:        22 July 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mono
PORTVERSION=	0.29
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.go-mono.com/archive/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An open source implementation of .NET Development Framework

USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_BISON=	yes
USE_GNOME=	gnomehack glib20 pkgconfig
USE_GMAKE=	yes
LIBTOOLFILES=	configure libgc/configure
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--program-transform-name=\'\' \
		--with-gc=included
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		cert2spc.1 cilc.1 ilasm.1 mcs.1 mint.1 mono.1 \
		monoburg.1 monodis.1 monostyle.1 oldmono.1 \
		sqlsharp.1
MAN5=		mono-config.5

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-signbit
.else
BROKEN=	"Does not work on -CURRENT with garbage collection enabled"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
