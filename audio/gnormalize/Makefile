# New ports collection makefile for:	gnormalize
# Date created:				27 Oct 2007
# Whom:				Denise H. G. <darcsis@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gnormalize
PORTVERSION=	0.52
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	darcsis@gmail.com
COMMENT=	An alternative for replaygain

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Audio/CD.pm:${PORTSDIR}/audio/p5-Audio-CD \
		${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/${PERL_ARCH}/auto/Encode/Encode.so:${PORTSDIR}/converters/p5-Encode \
		normalize:${PORTSDIR}/audio/normalize \
		cddb.pl:${PORTSDIR}/audio/p5-CDDB_get \
		lame:${PORTSDIR}/audio/lame \
		faac:${PORTSDIR}/audio/faac \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		mppenc:${PORTSDIR}/audio/musepack \
		mac:${PORTSDIR}/audio/mac \
		flac:${PORTSDIR}/audio/flac \
		faad:${PORTSDIR}/audio/faad

USE_PERL5_RUN=	yes
INSTALLS_ICONS=	yes

NO_BUILD=	yes

MAN1=		gnormalize.1

pre-extract:
	@${ECHO} ""
	@${ECHO} "[N-O-T-I-C-E]"
	@${ECHO} "	A threaded perl is needed to run ${PORTNAME}-${PORTVERSION}."
	@${ECHO} "	If your perl is not compiled with thread support. Consider"
	@${ECHO} "	recompiling your perl with thread support. For more information,"
	@${ECHO} "	please read ${PORTSDIR}/lang/perl5.8/Makefile."
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e 's,^PREFIX=.*,PREFIX=${PREFIX},; \
		s,^MANDIR=.*,MANDIR=${MANPREFIX}/man,; \
		s,^BASE=.*,BASE=${DATADIR},' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr/share/gnormalize,${DATADIR},' \
		${WRKSRC}/gnormalize

.include <bsd.port.mk>
