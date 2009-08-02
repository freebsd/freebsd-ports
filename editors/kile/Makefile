# New ports collection makefile for: kile
# Date created:		21 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kile
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	editors kde
MASTER_SITES=	SFE

MAINTAINER=	markus@FreeBSD.org
COMMENT=	A LaTeX source editor for KDE

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		identify:${PORTSDIR}/graphics/ImageMagick

CONFLICTS=	kile-i18n-[0-9]*

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

OPTIONS=	KPDF "Use KPDF and KDVI for viewing" on

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| syntax||g' ${WRKSRC}/src/kile/Makefile.in

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_KPDF)
RUN_DEPENDS+=	kpdf:${PORTSDIR}/graphics/kdegraphics3
.endif

.include <bsd.port.post.mk>
