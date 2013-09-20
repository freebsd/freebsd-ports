# Created by: Peter Ankerstal <peter@pean.org>
# $FreeBSD$

PORTNAME=	npretty
PORTVERSION=	0.9.3
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://www.pulia.nu/code/projects/npretty/ \
		${MASTER_SITE_LOCAL:S@%SUBDIR%@gabor@}

MAINTAINER=	peter@pean.org
COMMENT=	A simple web-gallery generator written in perl

RUN_DEPENDS=	p5-Image-ExifTool>=0:${PORTSDIR}/graphics/p5-Image-ExifTool \
		convert:${PORTSDIR}/graphics/ImageMagick \
		p5-forks>=0:${PORTSDIR}/devel/p5-forks

LIB_DEPENDS+=	Magick.*:${PORTSDIR}/graphics/ImageMagick

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

NO_STAGE=	yes
post-patch:
	@ ${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" ${WRKSRC}/npretty.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/npretty.pl ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/npretty
	${INSTALL_DATA} ${WRKSRC}/novideo.gif ${PREFIX}/etc/npretty
	${INSTALL_DATA} ${WRKSRC}/npretty_template.tpl ${PREFIX}/etc/npretty
	${INSTALL_DATA} ${WRKSRC}/npretty.conf ${PREFIX}/etc/npretty
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in BUGS COPYING README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
