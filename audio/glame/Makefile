# New ports collection makefile for:	glame
# Date created:				26 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glame
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful, fast, stable, and easily extensible sound editor for GNOME

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		ltdl.4:${PORTSDIR}/devel/libltdl

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libglade
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lltdl ${PTHREAD_LIBS}" \
		MAKEINFO="makeinfo --no-split"
INSTALLS_SHLIB=	yes

INFO=		glame glame-dev

post-extract:
	@cd ${WRKSRC}/doc && ${RM} -f *.info*

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g'
	@${GREP} -lR "<values\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<values\.h>|<limits.h>|'

.include <bsd.port.mk>
