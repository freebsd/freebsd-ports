# New ports collection makefile for:	musicbrainz
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	libmusicbrainz
PORTVERSION=	2.1.3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
    		http://uk.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	2nd generation incarnation of the CD Index - audio metadata

FORBIDDEN=	Multiple buffer overflow vulnerabilities

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

CONFLICTS=	musicbrainz-1.*

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
