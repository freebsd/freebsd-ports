PORTNAME=	aacgain
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://aacgain.altosdesign.com/alvarez/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Normalizes the volume of MP3 and AAC (MP4/M4A/QuickTime) media files
WWW=		http://aacgain.altosdesign.com/

LICENSE=	GPLv2

BROKEN=		Unfetchable
DEPRECATED=	Obsolete way of handling volume adjustment, consider using audio/rsgain
EXPIRATION_DATE=2023-09-30

GNU_CONFIGURE=	yes
USES=		gmake libtool tar:bzip2
PLIST_FILES=	bin/aacgain

CXXFLAGS+=	--std=c++98

.include <bsd.port.mk>
