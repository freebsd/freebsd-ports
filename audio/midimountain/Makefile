# ex:ts=8
# New ports collection makefile for:	midimountain
# Date created:			Aug 5, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	midimountain
PORTVERSION=	0.3.0
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www.midimountain.com/download/ \
		SF/${PORTNAME}/MidiMountain-linux/Version%20${PORTVERSION}		


MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIDI sequencer

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
.for file in midimountain.conf main.cpp
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/midimountain/${file}
.endfor
.for dir in pixmaps languages
	${REINPLACE_CMD} -e "s, ${dir}/, ${DATADIR}/${dir}/,g" ${WRKSRC}/midimountain/${dir}/Makefile.in
.endfor

.include <bsd.port.mk>
