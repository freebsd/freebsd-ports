# New ports collection makefile for:	gimageview
# Date Created:				5 Feb 2002
# Whom:		TATEISHI Katsuyuki <katsu@iec.hiroshima-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gimageview
PORTVERSION=	0.2.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkmmviewer

MAINTAINER=	katsu@iec.hiroshima-u.ac.jp

LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mimlib}!=""
USE_GNOME+=	imlib
PKGNAMESUFFIX=	-imlib
.endif

post-patch:
	@${PERL} -pi -e 's/DATADIRNAME=lib/DATADIRNAME=share/g' \
		${WRKSRC}/configure

post-configure:
.if !defined(USE_IMLIB)
	@${FIND} ${WRKSRC} -name 'Makefile' | ${XARGS} ${PERL} -pi.orig -e \
		's/^(GDK_IMLIB_(CFLAGS|LIBS) =).*$$/$${1}/'
.endif

.include <bsd.port.post.mk>
