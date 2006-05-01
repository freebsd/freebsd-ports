# Ports collection Makefile for:	cuttlefish
# Date created:				20 March 2006
# Whom:					Matthew Luckie <mjl@luckie.org.nz>
#
# $FreeBSD$
#

PORTNAME=	cuttlefish
PORTVERSION=	1.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.caida.org/tools/visualization/cuttlefish/code/

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Plots diurnal and geographical patterns of supplied data

RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		convert:${PORTSDIR}/graphics/ImageMagick \
		gifsicle:${PORTSDIR}/graphics/gifsicle

USE_PERL5_RUN=	yes
NO_BUILD=	yes

IMAGES=		caida_logo.gif caida_logo_gray.gif \
		japan-water-okinawa.jpg japan-water.jpg \
		world-day.jpg world-water.jpg

EXAMPLES=	japan-traces-small.config japan-traces.config \
		nyxem-hosts-both.config \
		witty-combined-small.config witty-combined.config

post-patch:
	@${REINPLACE_CMD} -e "s|../lib|../lib/cuttlefish|" \
		${WRKSRC}/bin/cuttlefish.pl
.for f in ${EXAMPLES}
	@${REINPLACE_CMD} -e "s|images|${PREFIX}/share/cuttlefish|" \
		${WRKSRC}/configs/${f}
.endfor

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/cuttlefish.pl ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/cuttlefish
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${EXAMPLESDIR}
.for f in Canvas.pm Control.pm Histogram.pm Image.pm Legend.pm Map.pm Util.pm
	@${INSTALL_DATA} ${WRKSRC}/lib/${f} ${PREFIX}/lib/cuttlefish/${f}
.endfor
.for f in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/configs/${f} ${EXAMPLESDIR}/${f}
.endfor
.for f in ${IMAGES}
	@${INSTALL_DATA} ${WRKSRC}/images/${f} ${DATADIR}/${f}
.endfor

.include <bsd.port.mk>
