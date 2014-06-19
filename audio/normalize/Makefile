# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	normalize
PORTVERSION=	0.7.7
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	alex@fafula.com
COMMENT=	Tool for adjusting the volume of wave/MP3 files to a standard level

LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad

USES=		shebangfix perl5 tar:bzip2 libtool
USE_PERL5=	run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-helper-search
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	XMMS MP3 OGG FLAC NLS
OPTIONS_DEFAULT=	MP3
OPTIONS_SUB=	yes
XMMS_DESC=	XMMS plugin

XMMS_LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms
XMMS_CONFIGURE_ENABLE=	xmms
MP3_RUN_DEPENDS+=	madplay:${PORTSDIR}/audio/madplay \
			lame:${PORTSDIR}/audio/lame
OGG_RUN_DEPENDS=	oggdec:${PORTSDIR}/audio/vorbis-tools
FLAC_RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
