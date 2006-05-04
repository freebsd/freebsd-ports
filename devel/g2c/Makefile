# ex:ts=8
# Ports collection makefile for:	g2c
# Date created:			Mar 21, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	g2c
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Glade to C translator

PLIST_FILES=	bin/g2c
USE_GNOME=	gtk12 gnomehack libxml orbit
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mbonobo} != "" && ${HAVE_GNOME:Mgnomedb} != ""
USE_GNOME+=	gnomeprefix bonobo gnomedb
PKGNAMESUFFIX+=	-gnome
.else
CONFIGURE_ARGS=	--disable-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
