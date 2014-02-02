# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	libstatgrab
PORTVERSION=	0.17
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.uk.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://ftp.uk.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://dl.ambiweb.de/mirrors/ftp.i-scream.org/%SUBDIR%/ \
		ftp://ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://ftp.i-scream.org/pub/i-scream/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Provides a useful interface to system statistics

DIST_SUBDIR=	i-scream
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig

CONFIGURE_ARGS+=	--disable-examples

.ifdef(WITHOUT_STATGRAB)
CONFIGURE_ARGS+=	--disable-statgrab
PLIST_SUB+=		STATGRAB="@comment "
.else
PLIST_SUB+=		STATGRAB=""
MAN1+=			statgrab.1 statgrab-make-mrtg-config.1 \
			statgrab-make-mrtg-index.1
.endif

.ifdef(WITHOUT_SAIDAR)
CONFIGURE_ARGS+=	--disable-saidar
PLIST_SUB+=		SAIDAR="@comment "
.else
PLIST_SUB+=		SAIDAR=""
MAN1+=			saidar.1
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
