# New ports collection makefile for: kile
# Date created:		21 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kile
PORTVERSION=	2.0.3
PORTREVISION=	4
CATEGORIES=	editors kde
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A LaTeX source editor for KDE

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		identify:${PORTSDIR}/graphics/ImageMagick

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

CONFLICTS=	kile-i18n-[0-9]*
PORTSCOUT=	limit:^2\.0\.

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes

OPTIONS_DEFINE=	KPDF
OPTIONS_DEFAULT=	KPDF
KPDF_DESC=	Use KPDF and KDVI for viewing

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| syntax||g' ${WRKSRC}/src/kile/Makefile.in

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKPDF}
RUN_DEPENDS+=	kpdf:${PORTSDIR}/graphics/kdegraphics3
.endif

.include <bsd.port.mk>
