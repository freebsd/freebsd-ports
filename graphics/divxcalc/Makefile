# ex:ts=8
# Ports collection makefile for:	divxcalc
# Date created:			Mar 21, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	divxcalc
PORTVERSION=	0.2
CATEGORIES=	graphics
MASTER_SITES=	http://tuxpower.f2g.net/divxcalc/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/automake14/automake/install-sh:${PORTSDIR}/devel/automake14

USE_REINPLACE=	yes
USE_GTK=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s,Bison ,Bison,g" ${WRKSRC}/configure

pre-configure:
.for file in config.guess config.sub install-sh missing mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake14/automake/${file} ${WRKSRC}
.endfor

.include <bsd.port.mk>
