# New ports collection makefile for: ithought
# Date created:		20 Feb 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	ithought
PORTVERSION=	a5
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ithought

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An extensible text management system

LIB_DEPENDS=    xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/libexec

USE_GNOMENG=	yes
USE_GNOME=	gtk12

post-patch:
	@${PERL} -i.orig -p \
		-e 's#`gnome-config --cflags gtk`#`${GTK_CONFIG} --cflags`#;' \
		-e 's#`gnome-config --cflags gtk xml`#`${GTK_CONFIG} --cflags; xml-config --cflags`#;' \
		-e 's#`gnome-config --libs gtk xml`#`${GTK_CONFIG} --libs; xml-config --libs`#;' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
