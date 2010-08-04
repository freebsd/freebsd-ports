# New ports collection makefile for:	lamarc
# Date created:		6 August 2001
# Whom:			Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lamarc
PORTVERSION=	2.1.5
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	http://evolution.gs.washington.edu/lamarc/download/ \
		http://www.c-s.li/ports/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	c-s@c-s.li
COMMENT=	A package of programs for computing population parameters

LICENSE=	ASL

OPTIONS=	WXGTK2 "Install wxWidgets" off

MAKE_JOBS_SAFE=	yes

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

.if defined(WITH_WXGTK2)
USE_WX=		2.8
CONFIGURE_ARGS+=	--with-wx-config=${WX_CONFIG}
PLIST_SUB+=	WXGTK2=""
.else
CONFIGURE_ARGS+=	--disable-converter
PLIST_SUB+=	WXGTK2="@comment "
.endif

.if defined(NOPORTDOCS)
INSTALL_TARGET=	install-exec-am
.endif

.include <bsd.port.mk>
