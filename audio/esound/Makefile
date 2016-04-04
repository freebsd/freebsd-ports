# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/esound/Makefile,v 1.1 2008/11/20 19:38:24 marcus Exp $

PORTNAME=	esound
PORTVERSION=	0.2.41
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound library for enlightenment package

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile

USES=		alias libtool:keepla pathfix pkgconfig:both tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ENV=	JW=false
INSTALL_TARGET=	install-strip

CONFLICTS=	py*-ro-[0-9]*

post-patch:
	@${REINPLACE_CMD} -e 's|esdconf_DATA = esd.conf|esdconf_DATA = |g' \
		-e '/^esd_LDADD =/s/$$/ -lm/' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/esd.conf ${STAGEDIR}${PREFIX}/etc/esd.conf.sample

.include <bsd.port.mk>
