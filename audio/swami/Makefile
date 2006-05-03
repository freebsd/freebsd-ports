# New ports collection makefile for:	Swami
# Date created:			25 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		swami
PORTVERSION=		0.9.2
PORTREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		An advanced instrument editor

LIB_DEPENDS=		popt:${PORTSDIR}/devel/popt \
			png:${PORTSDIR}/graphics/png \
			fluidsynth:${PORTSDIR}/audio/fluidsynth \
			sndfile:${PORTSDIR}/audio/libsndfile \
			audiofile:${PORTSDIR}/audio/libaudiofile

USE_X_PREFIX=		yes
USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		gnomelibs gnometarget
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng12|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/NEWS \
		${WRKSRC}/README \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
