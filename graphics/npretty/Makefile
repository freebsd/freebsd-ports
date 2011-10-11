# New ports collection makefile for:	npretty
# Date created:				11 October 2006
# Whom:					Peter Ankerstal <peter@pean.org>
#
# $FreeBSD$
#

PORTNAME=	npretty
PORTVERSION=	0.9.3
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.pulia.nu/code/projects/npretty/ \
		${MASTER_SITE_LOCAL:S@%SUBDIR%@gabor@}

MAINTAINER=	peter@pean.org
COMMENT=	A simple web-gallery generator written in perl

RUN_DEPENDS=	${SITE_PERL}/Image/ExifTool.pm:${PORTSDIR}/graphics/p5-Image-ExifTool \
		${SITE_PERL}/mach/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick \
		${SITE_PERL}/mach/forks.pm:${PORTSDIR}/devel/p5-forks

LIB_DEPENDS+=	Magick.*:${PORTSDIR}/graphics/ImageMagick

NO_BUILD=	yes
USE_PERL5_RUN=	yes

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
