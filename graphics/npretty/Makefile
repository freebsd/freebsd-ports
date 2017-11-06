# Created by: Peter Ankerstal <peter@pean.org>
# $FreeBSD$

PORTNAME=	npretty
DISTVERSIONPREFIX=	n
DISTVERSION=	0.9.3-1
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	peter@pean.org
COMMENT=	Simple web-gallery generator written in perl

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool \
		p5-forks>=0:devel/p5-forks
LIB_DEPENDS=	libMagickCore-6.so:graphics/ImageMagick

USE_GITHUB=	yes
GH_ACCOUNT=	gammy

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	npretty.pl

OPTIONS_DEFINE=	DOCS

post-patch:
	@ ${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" ${WRKSRC}/npretty.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/npretty.pl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/npretty
	${INSTALL_DATA} ${WRKSRC}/novideo.gif ${STAGEDIR}${PREFIX}/etc/npretty
	${INSTALL_DATA} ${WRKSRC}/npretty_template.tpl ${STAGEDIR}${PREFIX}/etc/npretty
	${INSTALL_DATA} ${WRKSRC}/npretty.conf ${STAGEDIR}${PREFIX}/etc/npretty
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in BUGS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
