# New ports collection makefile for:	Creox
# Date created:				18 Aug 2009
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	creox
DISTVERSION=	0.2.2rc2
PORTREVISION=	4
CATEGORIES=	audio kde
MASTER_SITES=	http://zyzstar.kosoru.com/projects/creox/downloads/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A real-time sound processor

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_KDELIBS_VER=	3
INSTALLS_ICONS=	yes

post-patch:
# Fix bogus test(1) syntax and remove superfluous -O2
	@${REINPLACE_CMD} -E 's,(if \[ [[:graph:]]+ )==,\1=, ; \
		s,-O2,,' ${WRKSRC}/configure
# FreeBSD does not have exp10f(3), use powf(3) instead
	@${REINPLACE_CMD} -e 's|exp10f(|powf(10., |' \
		${WRKSRC}/creox/dsp_flow/threadeffector.cpp \
		${WRKSRC}/creox/effects_dsp/tremoloprocessor.cpp \
		${WRKSRC}/creox/effects_dsp/phaserprocessor.cpp \
		${WRKSRC}/creox/effects_dsp/flangerprocessor.cpp \
		${WRKSRC}/creox/effects_dsp/echoprocessor.cpp \
		${WRKSRC}/creox/effects_dsp/distortionprocessor.cpp
# Fix std::fmaf (remove std:: prefix)
	@${REINPLACE_CMD} -e 's,std::fmaf,fmaf,' \
		${WRKSRC}/creox/effects_dsp/tremoloprocessor.cpp \
		${WRKSRC}/creox/effects_dsp/echoprocessor.cpp
# Add missing closing parentheses on line 186
	@${REINPLACE_CMD} -e '186s,);,)&,' \
		${WRKSRC}/creox/effects_dsp/tremoloprocessor.cpp

.include <bsd.port.mk>
