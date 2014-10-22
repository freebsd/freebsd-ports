# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	libstatgrab
PORTVERSION=	0.91
CATEGORIES=	devel
MASTER_SITES=	http://ftp.mirrorservice.org/pub/i-scream/libstatgrab/ \
		http://dl.ambiweb.de/mirrors/ftp.i-scream.org/libstatgrab/ \
		http://ftp.i-scream.org/pub/i-scream/libstatgrab/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Provides a useful interface to system statistics

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig libtool

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}

OPTIONS_DEFINE=	TOOLS DOCS
OPTIONS_DEFAULT=	TOOLS

TOOLS_DESC=	Build and install statgrab and saidar

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOOLS}
USES+=		shebangfix perl5
SHEBANG_FILES=	src/statgrab/statgrab-make-mrtg-config.in \
		src/statgrab/statgrab-make-mrtg-index.in
.else
CONFIGURE_ARGS+=	--disable-statgrab --disable-saidar
.endif

.include <bsd.port.mk>
