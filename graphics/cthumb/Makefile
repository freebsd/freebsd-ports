# New ports collection makefile for:    cthumb
# Date created:         30 July 2001
# Whom:                 dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	cthumb
PORTVERSION=	4.1
CATEGORIES=	graphics www
MASTER_SITES=	http://puchol.com/cpg/software/cthumb/

MAINTAINER=	dom@happygiraffe.net

RUN_DEPENDS=	${LOCALBASE}/bin/pnmscale:${PORTSDIR}/graphics/netpbm \
		${LOCALBASE}/bin/djpeg:${PORTSDIR}/graphics/jpeg \
		${SITE_PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
SITE_PERL_ARCH=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-themedir=${PREFIX}/share/${PORTNAME}

MAN1=		cthumb.1

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

post-configure:
	@${PERL} -pi \
		-e 's|cp -r|cp -Rf|g;' \
		${WRKSRC}/cthumb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cthumb ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cthumb.1 ${PREFIX}/man/man1
	${MKDIR} ${DATADIR}
.for theme in ${THEMES}
	${MKDIR} ${DATADIR}/${theme}
	${INSTALL_DATA} ${WRKSRC}/themes/${theme}/* ${DATADIR}/${theme}
.endfor
.if !defined(NOPRTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ChangeLog INSTALL README TO-DO VERSION cthumbrc.sample
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
