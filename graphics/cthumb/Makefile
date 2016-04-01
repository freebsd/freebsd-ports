# Created by: dom@happygiraffe.net
# $FreeBSD$

PORTNAME=	cthumb
PORTVERSION=	4.2
PORTREVISION=	4
CATEGORIES=	graphics www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themeable web picture album generator

RUN_DEPENDS=	${LOCALBASE}/bin/pnmscale:graphics/netpbm \
		${LOCALBASE}/bin/jhead:graphics/jhead \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-URI>=0:net/p5-URI

USES=		jpeg:run perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-themedir=${DATADIR}
CONFIGURE_ENV=	perl_path=${PERL}

PORTDOCS=	ChangeLog INSTALL README TO-DO VERSION cthumbrc.sample

THEMES=		blue-steel.theme \
		classic-clips.theme \
		classic.theme \
		crosshair.theme \
		film.theme \
		flaps.theme \
		float-medium.theme \
		float-more.theme \
		float-thick.theme \
		float.theme \
		ithumb.theme \
		neat-round.theme \
		neat-square.theme \
		oak.theme \
		postcard.theme \
		shiny-tube.theme \
		simpleframe.theme \
		slides-big.theme \
		slides-clean.theme \
		slides-huge.theme \
		slides-small.theme \
		spotlight.theme \
		tv-large.theme \
		tv.theme

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cthumb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cthumb.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for theme in ${THEMES}
	@${MKDIR} ${STAGEDIR}${DATADIR}/${theme}
	${INSTALL_DATA} ${WRKSRC}/themes/${theme}/* ${STAGEDIR}${DATADIR}/${theme}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
