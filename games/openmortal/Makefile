# New ports collection makefile for:  	openmortal
# Date created:       		20 Apr 2004
# Whom:  			krion@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	openmortal
PORTVERSION=	0.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A parody of the once popular coin-up fighting game, Mortal Kombat

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
USE_SDL=	mixer image sdl net

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|sdl11-config|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC}/src -name "*.cpp" | ${XARGS} \
		${REINPLACE_CMD} -e 's|SDL/|SDL11/|g' -e 's|<malloc.h>|<stdlib.h>|g'
	@${FIND} ${WRKSRC} -name "*.h" | ${XARGS} \
		${REINPLACE_CMD} -e 's|SDL/|SDL11/|g' -e 's|<malloc.h>|<stdlib.h>|g'

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
