# New ports collection makefile for:   dekagen
# Date created:        12 August 2003
# Whom:                Martin Kraft <martin.kraft@fal.de>
#
# $FreeBSD$
#

PORTNAME=	dekagen
PORTVERSION=	1.0.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/linux/apps/sound/convert/

MAINTAINER=	martin.kraft@fal.de
COMMENT=	A frontend to rip, convert and name MP3/Ogg

# The only reason for installing xmcd is, that dekagen uses cda
# for CDDB inquiries. You can safely 'make -DWITHOUT_XMCD', if you
# can do without inquiring the CDDB database. Dependencies of
# the xmcd package will install the encoders lame and oggenc (vorbis-tools),
# both of them are supported by dekagen.

.if !defined(WITHOUT_XMCD)
RUN_DEPENDS+=	cda:${PORTSDIR}/audio/xmcd
.endif

# If you want to use another ripper, eg. tosha or dagrab,
# you can safely 'make -DWITHOUT_CDPARANOIA'.

.if !defined(WITHOUT_CDPARANOIA)
RUN_DEPENDS+=	cdparanoia:${PORTSDIR}/audio/cdparanoia
.endif

MAN1=		dekagen.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/dekagen

.include <bsd.port.pre.mk>

NO_BUILD=	Shell Script
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dekagen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dekagen.1.gz ${PREFIX}/man/man1

.include <bsd.port.post.mk>
