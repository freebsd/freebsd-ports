# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	libstatgrab
PORTVERSION=	0.91
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.mirrorservice.org/pub/i-scream/libstatgrab/ \
		http://dl.ambiweb.de/mirrors/ftp.i-scream.org/libstatgrab/ \
		http://ftp.i-scream.org/pub/i-scream/libstatgrab/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Provides a useful interface to system statistics

LICENSE=	LGPL21

USES=		pathfix pkgconfig libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}

OPTIONS_DEFINE=	TOOLS DOCS
OPTIONS_DEFAULT=	TOOLS

TOOLS_DESC=	Build and install statgrab and saidar
TOOLS_CONFIGURE_ENABLE=	statgrab saidar
TOOLS_USES=	shebangfix perl5 ncurses
TOOLS_VARS=	SHEBANG_FILES+="src/statgrab/statgrab-make-mrtg-config.in \
				src/statgrab/statgrab-make-mrtg-index.in" \
		LICENSE+=GPLv2 LICENSE_COMB=multi

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200016
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_libstatgrab_memory__stats.c
.endif

.include <bsd.port.mk>
