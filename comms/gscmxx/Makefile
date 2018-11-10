# Created by: svmohr
# $FreeBSD$

PORTNAME=	gscmxx
PORTVERSION=	0.4.1
PORTREVISION=	11
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	svmohr@gmail.com
COMMENT=	Graphical frontend for scmxx

DEPRECATED=	Uses obsolete glib12
EXPIRATION_DATE=	2018-12-20

RUN_DEPENDS=	p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-Gtk-Perl>=0:x11-toolkits/p5-Gtk-Perl
BUILD_DEPENDS=	p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-Gtk-Perl>=0:x11-toolkits/p5-Gtk-Perl \
		scmxx:comms/scmxx \
		convert:graphics/ImageMagick6

USES=		perl5
USE_PERL5=	configure

USE_GNOME=	gtk12

do-install:
	cd ${WRKSRC} && make install PREFIX='${STAGEDIR}${PREFIX}'

.include <bsd.port.mk>
