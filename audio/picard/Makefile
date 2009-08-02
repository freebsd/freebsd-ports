# New ports collection makefile for:	picard
# Date created:		Sat Aug 20 15:26:15 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	picard
PORTVERSION=	0.11
CATEGORIES=	audio python
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		http://ftp.uk.musicbrainz.org/pub/musicbrainz/picard/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Next generation MusicBrainz Tagger

LIB_DEPENDS=	ofa.0:${PORTSDIR}/audio/libofa \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		discid.2:${PORTSDIR}/audio/libdiscid
RUN_DEPENDS=	py*-mutagen>=0:${PORTSDIR}/audio/py-mutagen \
		py*-qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		py*-qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		py*-qt4-network>=0:${PORTSDIR}/net/py-qt4-network \
		py*-qt4-xml>=0:${PORTSDIR}/textproc/py-qt4-xml

USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-patch:
	@${REINPLACE_CMD} '/with-libofa/s|False|True|;\
		/with-avcodec/s|False|True|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|libdiscid.so.0|libdiscid.so.2|g' \
		${WRKSRC}/picard/disc.py
	@${REINPLACE_CMD} 's|<av|<ffmpeg/av|' ${WRKSRC}/picard/musicdns/avcodec.c

.include <bsd.port.mk>
