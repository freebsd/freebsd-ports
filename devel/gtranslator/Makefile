# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/gtranslator/Makefile,v 1.12 2007/07/04 15:52:37 mezz Exp $

PORTNAME=	gtranslator
PORTVERSION=	1.1.7
PORTREVISION=	10
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME application for creating GNU gettext translation files

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell

USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gnomevfs2 libgnomeui
USES=		gettext gmake pkgconfig
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgnuregex
CONFIGURE_ARGS=	--disable-debug \
		--enable-compile-warnings=no

MAN1=		gtranslator.1 pozilla.sh.1

NO_STAGE=	yes
post-patch:
		@${REINPLACE_CMD} -e "s|-Werror||" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
