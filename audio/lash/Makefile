# New ports collection makefile for:	lash
# Date created:				2007-01-13
# Whom:			Edward Tomasz Napierala <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	lash
PORTVERSION=	0.5.4
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Session management system for JACK audio applications

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	jack:${PORTSDIR}/audio/jack \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		dssialsacompat:${PORTSDIR}/audio/libdssialsacompat

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-alsa-midi
USE_GNOME=	gnomehack gtk20 libxml2
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/dssi -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|texi2html --number|texi2html|' \
		${WRKSRC}/docs/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/docs/lash-manual-html-one-page/lash-manual.html \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
