PORTNAME=	dekagen
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/linux/apps/sound/convert/

MAINTAINER=	martin.kraft@fal.de
COMMENT=	Frontend to rip, convert, and name MP3/Ogg
WWW=		http://userpage.fu-berlin.de/~mbayer/tools/dekagen.html

DEPRECATED=	Abandonware, last release in 2004. Please consider using audio/cyanrip or audio/abcde
EXPIRATION_DATE=2023-03-31

# The only reason for installing xmcd is, that dekagen uses cda
# for CDDB inquiries. You can safely 'make -DWITHOUT_XMCD', if you
# can do without inquiring the CDDB database. Dependencies of
# the xmcd package will install the encoders lame and oggenc (vorbis-tools),
# both of them are supported by dekagen.

.if !defined(WITHOUT_XMCD)
RUN_DEPENDS+=	cda:audio/xmcd
.endif

# If you want to use another ripper, eg. tosha or dagrab,
# you can safely 'make -DWITHOUT_CDPARANOIA'.

.if !defined(WITHOUT_CDPARANOIA)
RUN_DEPENDS+=	cdparanoia:audio/cdparanoia
.endif

NO_BUILD=	Shell Script
PLIST_FILES=	bin/dekagen man/man1/dekagen.1.gz
DEFAULT_CDROM_DEVICE?=	/dev/acd0

post-patch:
	@${REINPLACE_CMD} -e \
	's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
	${WRKSRC}/dekagen

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dekagen ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dekagen.1.gz ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
