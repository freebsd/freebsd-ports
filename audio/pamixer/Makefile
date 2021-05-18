# Created by: Daniel Menelkir <menelkir@itroll.org>

PORTNAME=	pamixer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4-15
DISTVERSIONSUFFIX=	-g4ea2594
CATEGORIES=	audio

MAINTAINER=	menelkir@itroll.org
COMMENT=	Pulseaudio command line mixer

LICENSE=	GPLv3

LIB_DEPENDS+=	libpulse.so:audio/pulseaudio \
		libboost_program_options.so:devel/boost-libs

USES=		compiler:gcc-c++11-lib gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	cdemoulins

PLIST_FILES=	bin/pamixer man/man1/pamixer.1.gz

.include <bsd.port.mk>
