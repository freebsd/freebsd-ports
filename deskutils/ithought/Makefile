# New ports collection makefile for: ithought
# Date created:		20 Feb 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	ithought
PORTVERSION=	a4
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ithought

MAINTAINER=	nbm@FreeBSD.org

LIB_DEPENDS=    xml.5:${PORTSDIR}/textproc/libxml

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/libexec

ALL_TARGET=	ithought

USE_GTK=	yes

post-patch:
	@${PERL} -i.orig -p \
		-e 's#`gnome-config --cflags gtk`#`${GTK_CONFIG} --cflags`#;' \
		-e 's#`gnome-config --cflags gtk xml`#`${GTK_CONFIG} --cflags; xml-config --cflags`#;' \
		-e 's#`gnome-config --libs gtk xml`#`${GTK_CONFIG} --libs; xml-config --libs`#;' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
