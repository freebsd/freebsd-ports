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

USE_BISON=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s,Bison ,Bison,g" ${WRKSRC}/configure

pre-configure:
.for file in config.guess config.sub install-sh missing mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake14/automake/${file} ${WRKSRC}
.endfor

.include <bsd.port.mk>
