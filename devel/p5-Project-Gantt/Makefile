# New ports collection makefile for:	devel/p5-Project-Gantt
# Date created:				Thu Oct 21 16:46:26 CST 2004
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Project-Gantt
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AW/AWESTHOLM
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Create Gantt charts to manage project scheduling

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Class/Date.pm:${PORTSDIR}/devel/p5-Class-Date \
		${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/Gantt

MAN3=		Project::Gantt.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This program only support perl 5.8.0 or above
.endif

.include <bsd.port.post.mk>
