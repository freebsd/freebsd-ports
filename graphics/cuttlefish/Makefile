# Created by: Matthew Luckie <mjl@luckie.org.nz>
# $FreeBSD$

PORTNAME=	cuttlefish
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.caida.org/tools/visualization/cuttlefish/code/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plots diurnal and geographical patterns of supplied data

RUN_DEPENDS+=	p5-GD>=0:graphics/p5-GD \
		convert:graphics/ImageMagick \
		gifsicle:graphics/gifsicle

USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
SHEBANG_FILES=	bin/cuttlefish.pl

IMAGES=		caida_logo.gif caida_logo_gray.gif \
		japan-water-okinawa.jpg japan-water.jpg \
		world-day.jpg world-water.jpg

EXAMPLES=	japan-traces-small.config japan-traces.config \
		nyxem-hosts-both.config \
		witty-combined-small.config witty-combined.config

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e "s|../lib|../lib/cuttlefish|" \
		${WRKSRC}/bin/cuttlefish.pl
.for f in ${EXAMPLES}
	@${REINPLACE_CMD} -e "s|images|${PREFIX}/share/cuttlefish|" \
		${WRKSRC}/configs/${f}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/cuttlefish.pl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/cuttlefish
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in Canvas.pm Control.pm Histogram.pm Image.pm Legend.pm Map.pm Util.pm
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${STAGEDIR}${PREFIX}/lib/cuttlefish/${f}
.endfor
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/configs/${f} ${STAGEDIR}${EXAMPLESDIR}/${f}
.endfor
.for f in ${IMAGES}
	${INSTALL_DATA} ${WRKSRC}/images/${f} ${STAGEDIR}${DATADIR}/${f}
.endfor

.include <bsd.port.mk>
