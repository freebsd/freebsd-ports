# New ports collection makefile for: gqradio
# Date created:		13 Apr 2003
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	gqradio
PORTVERSION=	0.99.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=gqmpeg

MAINTAINER=	stefan.jahn@nemesis-sektor.de
COMMENT=	GTK based FM tuner

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GNOME=	gtk12 gdkpixbuf
USE_REINPLACE=	yes
CONFIGURE_ENV=	LIBS=-L${LOCALBASE}/lib \
		CPPFLAGS=-I${LOCALBASE}/include

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
ONLY_FOR_ARCHS=	i386
.else
ONLY_FOR_ARCHS=	alpha i386 ia64
.endif

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomelibs
.endif

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You may use the following build options:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "      WITHOUT_PNG=yes  Don't depend on libpng. Skin editor will not"
	@${ECHO_CMD} "                       be able to save 'internal' skins"
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} -e 's|_nl_domain_bindings|libintl_nl_domain_bindings|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
